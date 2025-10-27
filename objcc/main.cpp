#include <iostream>
#include <AppKit/NSApplication.hpp>
#include <internals/AppKitDefines.hpp>
#include <Foundation/NSValue.hpp>
#include <AppKit/NSWindow.hpp>

class MyAppDelegate : public NS::ApplicationDelegate{
public:
    void applicationWillFinishLaunching(NS::Notification *pNotification) override{
        window = new NS::Window(CGRectMake(0, 0, 400, 400), NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable, NSBackingStoreBuffered);
        window->setTitle("Window");
        window->makeKeyAndOrderFront(nullptr);
    }
    void applicationDidFinishLaunching(NS::Notification *pNotification) override{
        
    }
    MyAppDelegate(void){
        
    }
    ~MyAppDelegate(void){
        delete window;
    }
private:
    NS::Window* window;
};

struct PPoint{
    int x;
    int y;
    PPoint(int x, int y): x(x), y(y){}
};

std::ostream& operator<<(std::ostream& os, PPoint* p){
    os<<"X: "<<p->x<<" Y: "<<p->y<<'\n';
    return os;
}


int main(void){
    auto start = std::chrono::high_resolution_clock::now();
    MyAppDelegate appDel;
    NS::Application app;
    app.setDelegate(&appDel);
    app.run();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "Time Taken: " << duration.count() << " µs" << '\n';
    return EXIT_SUCCESS;
}
