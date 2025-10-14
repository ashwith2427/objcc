#include <iostream>
#include <Foundation/NSObject.hpp>

int main(void){
    auto start = std::chrono::high_resolution_clock::now();
    NS::Object* obj = new NS::Object();
    std::cout << std::boolalpha << obj->isProxy() << '\n';
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Time Taken: " << duration.count() << " ms" << '\n';
    return EXIT_SUCCESS;
}
