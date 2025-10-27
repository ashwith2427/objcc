#include <Foundation/NSValue.hpp>

namespace NS{ 
Value::Value(const void* pointer): Object("NSValue", [=, this]{
    return this->message<id>(_NS_SELECTOR(valueWithPointer_)).sendToClass<const void*>(pointer);
}){}
void* Value::pointerValue() const{
    return this->message<void*>(_NS_SELECTOR(pointerValue)).send();
}
}
