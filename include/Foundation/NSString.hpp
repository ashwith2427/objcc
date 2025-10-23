#pragma once
#include <Foundation/NSObject.hpp>
#include <internals/Enums.hpp>

namespace NS{
class String : public Object{
    BASE_TEMPLATE(String, Object);
public:
    String(void): Object("NSString"){}
    String(const char* str);
    const char* cString();
    NSUInteger length();
};
}
