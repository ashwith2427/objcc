#include <iostream>
#include <Foundation/NSObject.hpp>

int main(void){
    NS::Object obj;
    std::cout << std::boolalpha << obj.isProxy() << '\n';
    return EXIT_SUCCESS;
}
