#pragma once
#include <internals/objc_bridge_functions.hpp>

#define _APPKIT_CLASS(name) (NS::Private::Class::s_k##name)
#define _APPKIT_SELECTOR(accessor) (NS::Private::Selector::s_k##accessor)

#define NS_PRIVATE_VISIBILITY __attribute__((visibility("default")))
#define APPKIT_PRIVATE_DEF_CLASS(name)   \
    static void* s_k##name NS_PRIVATE_VISIBILITY = objc_lookUpClass(#name)
#define APPKIT_PRIVATE_DEF_SELECTOR(accessor, name)  \
    static  SEL s_k##accessor NS_PRIVATE_VISIBILITY = sel_registerName(name)

namespace NS{
    namespace Private{
        namespace Class{
            APPKIT_PRIVATE_DEF_CLASS(NSApplication);
            APPKIT_PRIVATE_DEF_CLASS(NSWindow);
            APPKIT_PRIVATE_DEF_CLASS(NSView);
            APPKIT_PRIVATE_DEF_CLASS(NSViewController);
        }
    }
}

namespace NS{
    namespace Private{
        namespace Selector{
            APPKIT_PRIVATE_DEF_SELECTOR(sharedApplication, "sharedApplication");
            APPKIT_PRIVATE_DEF_SELECTOR(setDelegate_, "setDelegate:");
            APPKIT_PRIVATE_DEF_SELECTOR(run, "run");
            APPKIT_PRIVATE_DEF_SELECTOR(applicationWillFinishLaunching_, "applicationWillFinishLaunching:");
            APPKIT_PRIVATE_DEF_SELECTOR(applicationDidFinishLaunching_, "applicationDidFinishLaunching:");
            APPKIT_PRIVATE_DEF_SELECTOR(applicationShouldTerminateAfterLastWindowClosed_, "applicationShouldTerminateAfterLastWindowClosed:");
            APPKIT_PRIVATE_DEF_SELECTOR(setActivationPolicy_, "setActivationPolicy:");
            // NSWindow
            APPKIT_PRIVATE_DEF_SELECTOR(initWithContentRect_styleMask_backing_defer_, "initWithContentRect:styleMask:backing:defer:");
            APPKIT_PRIVATE_DEF_SELECTOR(setTitle_, "setTitle:");
            APPKIT_PRIVATE_DEF_SELECTOR(makeKeyAndOrderFront_, "makeKeyAndOrderFront:");
            APPKIT_PRIVATE_DEF_SELECTOR(setContentViewController_, "setContentViewController:");
            // NSView
            APPKIT_PRIVATE_DEF_SELECTOR(initWithFrame_, "initWithFrame:");
            // NSViewController
            APPKIT_PRIVATE_DEF_SELECTOR(view, "view");
            APPKIT_PRIVATE_DEF_SELECTOR(setView_, "setView:");
            APPKIT_PRIVATE_DEF_SELECTOR(viewDidLoad, "viewDidLoad");
            APPKIT_PRIVATE_DEF_SELECTOR(loadView, "loadView");
        }
    }
}
