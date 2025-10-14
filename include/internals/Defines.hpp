#pragma once
#ifndef DEFINES_H
#define DEFINES_H
extern "C"{
typedef struct objc_class* Class;
typedef struct objc_object* id;
typedef struct objc_selector* SEL;
typedef struct objc_object Protocol;

struct objc_super{
    id reciever;
    Class super_class;
};

extern Class        objc_getClass           (const char*);
extern const char*  class_getName           (Class);
extern id           objc_msgSend            (id, SEL, ...);
extern double       objc_msgSend_fpret      (id, SEL, ...);
extern void         objc_msgSend_stret      (void*, id, SEL, ...);
extern SEL          sel_registerName        (const char*);
extern Class        object_getClass         (id);
extern Class        objc_lookUpClass        (const char*);
}
#endif

#define _NS_CLASS(name)         (NS::Private::Class::s_k##name)
#define _NS_SELECTOR(accessor)  (NS::Private::Selector::s_k##accessor)

#define NS_PRIVATE_VISIBILITY __attribute__((visibility("default")))
#define GET_CLASS(name)                                                  \
    static void* s_k##name NS_PRIVATE_VISIBILITY = objc_lookUpClass(#name)
#define GET_SELECTOR(accessor, name)                                     \
    static SEL s_k##accessor NS_PRIVATE_VISIBILITY = sel_registerName(name)

namespace NS{
    namespace Private{
        namespace Class{
            GET_CLASS(NSObject);
            GET_CLASS(NSString);
            GET_CLASS(NSUInteger);
        }
    }
}

namespace NS{
    namespace Private{
        namespace Selector{
            // NSObject
            GET_SELECTOR(init, "init");
            GET_SELECTOR(alloc, "alloc");
            GET_SELECTOR(getClass, "class");
            GET_SELECTOR(superclass, "superclass");
            GET_SELECTOR(isEqual_, "isEqual:");
            GET_SELECTOR(self, "self");
            GET_SELECTOR(isKindOfClass_, "isKindOfClass:");
            GET_SELECTOR(isMemberOfClass_, "isMemberOfClass:");
            GET_SELECTOR(respondsToSelector_, "respondsToSelector:");
            GET_SELECTOR(conformsToProtocol_, "conformsToProtocol:");
            GET_SELECTOR(description, "description");
            GET_SELECTOR(debugDescription, "debugDescription");
            GET_SELECTOR(performSelector_, "performSelector:");
            GET_SELECTOR(performSelector_withObject_, "performSelector:withObject:");
            GET_SELECTOR(isProxy, "isProxy");
            GET_SELECTOR(retain, "retain");
            GET_SELECTOR(release, "release");
            GET_SELECTOR(autorelease, "autorelease");
            GET_SELECTOR(zone, "zone");
            // NSString
            GET_SELECTOR(initWithUTF8String_, "initWithUTF8String:");
        }
    }
}
