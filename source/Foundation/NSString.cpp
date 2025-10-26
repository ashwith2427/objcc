#include <Foundation/NSString.hpp>

namespace NS {
String::String(const char* str): Object("NSString", [=, this]{
    return this->message<id>(_NS_SELECTOR(stringWithUTF8String_)).sendToClass(str);
}){}
const char* String::cString(){
    return this->message<const char*>(_NS_SELECTOR(UTF8String)).sendToClass();
}
NSUInteger String::length(){
    return this->message<NSUInteger>(_NS_SELECTOR(length)).send();
}
}
