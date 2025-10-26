#include <iostream>
#include <AppKit/NSApplication.hpp>
#include <Foundation/NSValue.hpp>

class PPoint{
public:
    int x;
    int y;
    PPoint(int x, int y):x(x), y(y){}
};

int main(void){
    auto start = std::chrono::high_resolution_clock::now();
    PPoint* p = new PPoint(5, 6);
    NS::Value* val = new NS::Value(p);
    PPoint* pointer_p = (PPoint*)val->pointerValue();
    std::cout << "X: " << pointer_p->x << " Y: " << pointer_p->y << '\n';
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Time Taken: " << duration.count() << " µs" << '\n';
    return EXIT_SUCCESS;
}
