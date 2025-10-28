#include <AppKit/NSViewController.hpp>
#include <internals/AppKitDefines.hpp>
#include <Foundation/NSValue.hpp>
#include <internals/NSEnums.hpp>

namespace NS{
ViewController::ViewController(void): Object("NSViewController", [=, this]{
    Class base = (Class)_APPKIT_CLASS(NSViewController);
    Class cls = objc_allocateClassPair(base, "cppNSViewController", 0);
    objc_setAssociatedObject((id)cls, "cppNSViewController", (id)*this, OBJC_ASSOCIATION_ASSIGN);
    typedef void(*DispatchFunction)(id, SEL, id);
    DispatchFunction viewDidLoadIMP = [](id self, SEL, id){
        auto cppThis = reinterpret_cast<ViewController*>(objc_getAssociatedObject((id)object_getClass(self), "cppNSViewController"));
        if(cppThis) cppThis->viewDidLoad();
    };
    DispatchFunction loadViewIMP = [](id self, SEL, id){
        auto cppThis = reinterpret_cast<ViewController*>(objc_getAssociatedObject((id)object_getClass(self), "cppNSViewController"));
        if(cppThis) cppThis->loadView();
    };
    class_addMethod(cls, _APPKIT_SELECTOR(viewDidLoad), (IMP)viewDidLoadIMP, "v@:");
    class_addMethod(cls, _APPKIT_SELECTOR(loadView), (IMP)loadViewIMP, "v@:");
    objc_registerClassPair(cls);
    id alloced = Message<id>((Class)_APPKIT_CLASS(NSViewController), _APPKIT_SELECTOR(alloc)).send();
    return Message<id>(alloced, _APPKIT_SELECTOR(init)).send();
}){
    
}
void ViewController::setView(const View *view){
    this->message<void>(_APPKIT_SELECTOR(setView_)).send((id)*view);
}
}
