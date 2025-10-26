#include <AppKit/NSApplication.hpp>
#include <internals/AppKitDefines.hpp>

namespace NS{
Application* Application::sharedApplication(){
    return this->message<Application*>(_APPKIT_SELECTOR(sharedApplication)).send();
}
void Application::setDelegate(ApplicationDelegate *delegate){
    
}
}
