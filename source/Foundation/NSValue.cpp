#include <Foundation/NSValue.hpp>
#include <internals/NSDefines.hpp>

namespace NS{
Value::Value(void): Object("NSValue"){}
Value::Value(const void* pointer): Object("NSValue", [=, this]{
    return this->message<id>(_NS_SELECTOR(valueWithPointer_)).sendToClass(pointer);
}){}
void* Value::pointerValue(){
    return this->message<void*>(_NS_SELECTOR(pointerValue)).send();
}
}
