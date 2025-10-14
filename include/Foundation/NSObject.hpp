#pragma once
#include <internals/RefObject.hpp>

namespace NS{
class Object : public Ref::Object{
public:
    BASE_TEMPLATE(Object, Ref::Object);
    Object(void): Ref::Object("NSObject"){}
};
}
