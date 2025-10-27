#include <AppKit/NSWindow.hpp>
#include <internals/AppKitDefines.hpp>
#include <Foundation/NSString.hpp>

namespace NS{
Window::Window(void) : Object("NSWindow"){}
Window::Window(CGRect size, NSWindowStyleMask styleMask, NSBackingStoreType backing) : Object("NSWindow", [=, this]{
    return this->message<id>( _APPKIT_SELECTOR(initWithContentRect_styleMask_backing_defer_)).send(size, styleMask, backing, false);
}){}
void Window::setTitle(const std::string &title){
    NS::String t(title.c_str());
    this->message<void>(_APPKIT_SELECTOR(setTitle_)).send((id)t);
}
void Window::makeKeyAndOrderFront(id sender){
    this->message<void>(_APPKIT_SELECTOR(makeKeyAndOrderFront_)).send(sender);
}
}
