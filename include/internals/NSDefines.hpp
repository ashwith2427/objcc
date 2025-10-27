#pragma once
#include <internals/objc_bridge_functions.hpp>

#define _NS_CLASS(name)         (NS::Private::Class::s_k##name)
#define _NS_SELECTOR(accessor)  (NS::Private::Selector::s_k##accessor)

#define NS_PRIVATE_VISIBILITY __attribute__((visibility("default")))
#define NS_PRIVATE_DEF_CLASS(name)                                                  \
    static void* s_k##name NS_PRIVATE_VISIBILITY = objc_lookUpClass(#name)
#define NS_PRIVATE_DEF_SELECTOR(accessor, name)                                     \
    static SEL s_k##accessor NS_PRIVATE_VISIBILITY = sel_getUid(name)

namespace NS{
    namespace Private{
        namespace Class{
            NS_PRIVATE_DEF_CLASS(NSObject);
            NS_PRIVATE_DEF_CLASS(NSString);
            NS_PRIVATE_DEF_CLASS(NSValue);
            NS_PRIVATE_DEF_CLASS(NSUInteger);
        }
    }
}

namespace NS{
    namespace Private{
        namespace Selector{
            // NSObject
            NS_PRIVATE_DEF_SELECTOR(init, "init");
            NS_PRIVATE_DEF_SELECTOR(alloc, "alloc");
            NS_PRIVATE_DEF_SELECTOR(getClass, "class");
            NS_PRIVATE_DEF_SELECTOR(superclass, "superclass");
            NS_PRIVATE_DEF_SELECTOR(isEqual_, "isEqual:");
            NS_PRIVATE_DEF_SELECTOR(self, "self");
            NS_PRIVATE_DEF_SELECTOR(isKindOfClass_, "isKindOfClass:");
            NS_PRIVATE_DEF_SELECTOR(isMemberOfClass_, "isMemberOfClass:");
            NS_PRIVATE_DEF_SELECTOR(respondsToSelector_, "respondsToSelector:");
            NS_PRIVATE_DEF_SELECTOR(conformsToProtocol_, "conformsToProtocol:");
            NS_PRIVATE_DEF_SELECTOR(description, "description");
            NS_PRIVATE_DEF_SELECTOR(debugDescription, "debugDescription");
            NS_PRIVATE_DEF_SELECTOR(performSelector_, "performSelector:");
            NS_PRIVATE_DEF_SELECTOR(performSelector_withObject_, "performSelector:withObject:");
            NS_PRIVATE_DEF_SELECTOR(hash, "hash");
            NS_PRIVATE_DEF_SELECTOR(isProxy, "isProxy");
            NS_PRIVATE_DEF_SELECTOR(retain, "retain");
            NS_PRIVATE_DEF_SELECTOR(release, "release");
            NS_PRIVATE_DEF_SELECTOR(retainCount, "retainCount");
            NS_PRIVATE_DEF_SELECTOR(autorelease, "autorelease");
            NS_PRIVATE_DEF_SELECTOR(zone, "zone");
            // NSString
            NS_PRIVATE_DEF_SELECTOR(initWithUTF8String_, "initWithUTF8String:");
            NS_PRIVATE_DEF_SELECTOR(length, "length");
            NS_PRIVATE_DEF_SELECTOR(UTF8String, "UTF8String");
            NS_PRIVATE_DEF_SELECTOR(stringWithUTF8String_, "stringWithUTF8String:");
            // NSValue
            NS_PRIVATE_DEF_SELECTOR(valueWithPointer_, "valueWithPointer:");
            NS_PRIVATE_DEF_SELECTOR(pointerValue, "pointerValue");
        }
    }
}
