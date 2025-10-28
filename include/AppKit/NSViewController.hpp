#pragma once
#include <Foundation/NSObject.hpp>
#include <AppKit/NSView.hpp>

namespace NS{
class ViewController : public Object{
    BASE_TEMPLATE(ViewController, Object);
public:
    ViewController(void);
    void setView(const View* view);
    virtual void viewDidLoad(){}
    virtual void loadView(){}
};
}

void test();
