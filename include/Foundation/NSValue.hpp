#pragma once
#ifndef NSVALUE_H
#define NSVALUE_H
#include <Foundation/NSObject.hpp>

namespace NS{
class Value: public Object{
public:
    Value(void);
    Value(const void* pointer);
    void* pointerValue();
};
}
#endif
