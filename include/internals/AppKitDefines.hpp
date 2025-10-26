#pragma once
#ifndef APPKIT_DEFINES_H
#define APPKIT_DEFINES_H

#include <internals/objc_bridge_functions.hpp>
#define _APPKIT_CLASS(name)         (NS::Private::Class::s_k##name)
#define _APPKIT_SELECTOR(accessor)  (NS::Private::Selector::s_k##accessor)

#define NS_PRIVATE_VISIBILITY __attribute__((visibility("default")))
#define GET_CLASS(name)                                                  \
    static void* s_k##name NS_PRIVATE_VISIBILITY = objc_lookUpClass(#name)
#define GET_SELECTOR(accessor, name)                                     \
    static SEL s_k##accessor NS_PRIVATE_VISIBILITY = sel_registerName(name)

namespace NS::Private::Class{
    GET_CLASS(NSApplication);
    GET_CLASS(NSWindow);
}

namespace NS::Private::Selector{
    GET_SELECTOR(sharedApplication, "sharedApplication");
    GET_SELECTOR(setDelegate_, "setDelegate:");
    GET_SELECTOR(run, "run");
    GET_SELECTOR(applicationWillFinishLaunching_, "applicationWillFinishLaunching:");
    GET_SELECTOR(applicationDidFinishLaunching_, "applicationDidFinishLaunching:");
    GET_SELECTOR(appicationShouldTerminateAfterLastWindowClosed_, "applicationShouldTerminateAfterLastWindowClosed:");
    GET_SELECTOR(setActivationPolicy_, "setActivationPolicy:");
}

#endif
