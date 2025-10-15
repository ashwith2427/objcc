#include <Foundation/NSObject.hpp>
#include <internals/Enums.hpp>

namespace NS{
class String : public Object{
    BASE_TEMPLATE(String, Object);
public:
    String(void): Object("NSString"){}
    String(const char* str): Object("NSString", [=, this]{
        return this->message<id>("initWithUTF8String:").send<const char*>(str);
    }){}
    
    const char* cString(){
        return this->message<const char*>(_NS_SELECTOR(UTF8String)).send();
    }
    
    NSUInteger length(){
        return this->message<NSUInteger>(_NS_SELECTOR(length)).send();
    }
};
}
