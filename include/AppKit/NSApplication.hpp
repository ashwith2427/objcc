#pragma once
#ifndef NSAPPLICATION_H
#define NSAPPLICATION_H
#include <Foundation/NSObject.hpp>
#include <Foundation/NSNotification.hpp>
#include <Foundation/NSValue.hpp>
namespace NS{
class ApplicationDelegate{
public:
    virtual void applicationWillFinishLaunching(NS::Notification* pNotification){}
    virtual void applicationDidFinishLaunching(NS::Notification* pNotification){}
    virtual bool applicationShouldTerminateAfterLastWindowClosed(class Application* pNotification){
        return true;
    };
};

class Application : public Object{
public:
    Application( void );
    void run();
    void setDelegate(ApplicationDelegate* delegate);
private:
    NS::Value* wrapper;
};
}
#endif
