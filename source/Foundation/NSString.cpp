#include <Foundation/NSString.hpp>

namespace NS {
String::String(const char* str): Object("NSString", [=, this]{
    return this->message<id>("initWithUTF8String:").send<const char*>(str);
}){}
const char* String::cString(){
    return this->message<const char*>(_NS_SELECTOR(UTF8String)).send();
}
NSUInteger String::length(){
    return this->message<NSUInteger>(_NS_SELECTOR(length)).send();
}
}
