#include <iostream>
#include <Foundation/NSString.hpp>
#include <Foundation/Foundation.h>

int main(void){
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Time Taken: " << duration.count() << " ms" << '\n';
    return EXIT_SUCCESS;
}
