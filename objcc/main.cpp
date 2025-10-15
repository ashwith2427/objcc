#include <iostream>
#include <Foundation/NSObject.hpp>
#include <Foundation/NSString.hpp>

int main(void){
    auto start = std::chrono::high_resolution_clock::now();
    NS::String* string = new NS::String("Hello");
    std::cout<<string->cString();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Time Taken: " << duration.count() << " ms" << '\n';
    return EXIT_SUCCESS;
}
