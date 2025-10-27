#include <Foundation/NSObject.hpp>
#include <CoreGraphics/CGGeometry.h>
#include <internals/AppKitEnums.hpp>

namespace NS{
class Window : public Object{
    BASE_TEMPLATE(Window, Object);
public:
    Window(void);
    Window(CGRect size, NSWindowStyleMask styleMask, NSBackingStoreType backing);
    void setTitle(std::string const& title);
    void makeKeyAndOrderFront(id sender);
};
}
