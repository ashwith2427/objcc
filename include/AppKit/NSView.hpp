#pragma once
#include <Foundation/NSObject.hpp>
#include <CoreGraphics/CGGeometry.h>

namespace NS{
class View : public Object{
    BASE_TEMPLATE(View, Object);
public:
    View(CGRect frame);
};
}
