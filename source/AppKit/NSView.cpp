#include <AppKit/NSView.hpp>
#include <internals/AppKitDefines.hpp>

namespace NS{
View::View(CGRect frame): Object("NSView", [=, this]{
    return this->message<id>(_APPKIT_SELECTOR(initWithFrame_)).send(frame);
}){}
}

