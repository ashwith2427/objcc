#pragma once
#include <Foundation/NSObject.hpp>

namespace NS{
class Value: public Object{
    BASE_TEMPLATE(Value, Object);
public:
    Value(void): Object("NSValue"){}
    Value(const void* pointer);
    void* pointerValue() const;
};
}
