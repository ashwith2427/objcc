#pragma once
#include <internals/RefObject.hpp>

namespace NS{
class Object : public Ref::Object{
    BASE_TEMPLATE(Object, Ref::Object);
public:
    Object(void): Ref::Object("NSObject"){}
};
}
