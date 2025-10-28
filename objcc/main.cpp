#include <iostream>
#include <AppKit/AppKit.hpp>
#include <Foundation/Foundation.hpp>

class MyViewController : public NS::ViewController{
public:
    void viewDidLoad() override{
        std::cout << "View Did Load\n";
    }
    void loadView() override{
        std::cout<<"View loading....\n";
        view = new NS::View(CGRectMake(0, 0, 400, 400));
        this->setView(view);
    }
    ~MyViewController(void){
        delete view;
    }
private:
    NS::View* view;
};

class MyAppDelegate : public NS::ApplicationDelegate{
public:
    void applicationWillFinishLaunching(NS::Notification *pNotification) override{
        window = new NS::Window(CGRectMake(0, 0, 400, 400), NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable, NSBackingStoreBuffered);
        window->setTitle("Window");
        window->makeKeyAndOrderFront(nullptr);
        controller = new MyViewController();
        window->setContentViewController(controller);
        if(*controller == nullptr){
            std::cout<<"Controller is empty....\n";
        }
    }
    void applicationDidFinishLaunching(NS::Notification *pNotification) override{
        
    }
    MyAppDelegate(void){
        
    }
    ~MyAppDelegate(void){
        delete controller;
        delete window;
    }
private:
    NS::Window* window;
    MyViewController* controller;
};



int main(void){
    auto start = std::chrono::high_resolution_clock::now();
    MyAppDelegate appDel;
    NS::Application app;
    app.setDelegate(&appDel);
    app.run();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout << "Time Taken: " << duration.count() << " ms" << '\n';
    return EXIT_SUCCESS;
}
