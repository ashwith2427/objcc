#include <AppKit/NSApplication.hpp>
#include <Foundation/NSValue.hpp>
#include <internals/AppKitDefines.hpp>
#include <iostream>

namespace NS{

Application::Application(): Object("NSApplication", [=, this]{
    return this->message<id>(_APPKIT_SELECTOR(sharedApplication)).sendToClass();
}){}

void Application::setDelegate(ApplicationDelegate *delegate){
    NS::Value wrapper(delegate);
    typedef void (*DispatchFunction)(id, SEL, id);
    DispatchFunction willFinishLaunching = [](id pSelf, SEL, id pData){
        auto del = reinterpret_cast<ApplicationDelegate*>(objc_msgSend(pSelf, _NS_SELECTOR(pointerValue)));
        del->applicationWillFinishLaunching((Notification*)pData);
    };
    DispatchFunction didFinishLaunching = [](id pSelf, SEL, id pData){
        auto del = reinterpret_cast<ApplicationDelegate*>(objc_msgSend(pSelf, _NS_SELECTOR(pointerValue)));
        del->applicationDidFinishLaunching((Notification*)pData);
    };
    DispatchFunction shouldTerminate = [](id pSelf, SEL, id pData){
        auto del = reinterpret_cast<ApplicationDelegate*>(objc_msgSend(pSelf, _NS_SELECTOR(pointerValue)));
        del->applicationShouldTerminateAfterLastWindowClosed((Application*)pData);
    };
    class_addMethod((Class)_NS_CLASS(NSValue), _APPKIT_SELECTOR(applicationWillFinishLaunching_), (IMP)willFinishLaunching, "v@:@");
    class_addMethod((Class)_NS_CLASS(NSValue), _APPKIT_SELECTOR(applicationDidFinishLaunching_), (IMP)didFinishLaunching, "v@:@");
    class_addMethod((Class)_NS_CLASS(NSValue), _APPKIT_SELECTOR(applicationShouldTerminateAfterLastWindowClosed_), (IMP)shouldTerminate, "v@:@");
    this->message<void>(_APPKIT_SELECTOR(setDelegate_)).send<id>((id)wrapper);
}
void Application::run(){
    this->message<void>(_APPKIT_SELECTOR(run)).send();
}
}
