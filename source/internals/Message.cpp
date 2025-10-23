#include <internals/Message.hpp>
#include <string>

template <>
class Base::Object<MessageBase>::IMPL{
public:
    IMPL(void);
    ~IMPL(void);
    IMPL(IMPL const& o);
    IMPL(id cls, std::string const& selector);
    IMPL(id cls, SEL selector);
    id _object;
    SEL _selector;
};

Base::Object<MessageBase>::IMPL::IMPL(void):_object(nullptr), _selector(nullptr){}

Base::Object<MessageBase>::IMPL::~IMPL(void){}

Base::Object<MessageBase>::IMPL::IMPL(IMPL const& o): _object(o._object), _selector(o._selector){}

Base::Object<MessageBase>::IMPL::IMPL(id cls, std::string const& selector): _object(cls), _selector(sel_registerName(selector.c_str())){}

Base::Object<MessageBase>::IMPL::IMPL(id cls, SEL selector):
    _object(cls), _selector(selector){}


MessageBase::MessageBase(id cls, SEL selector):
    Base::Object<MessageBase>(cls, selector){}

MessageBase::MessageBase(id cls, std::string const& selector): Base::Object<MessageBase>(cls, selector){}

MessageBase::MessageBase(Class cls, std::string const& selector): Base::Object<MessageBase>(reinterpret_cast<id>(cls), selector){}

MessageBase::MessageBase(Class cls, SEL selector):
    Base::Object<MessageBase>(reinterpret_cast<id>(cls), selector){}

MessageBase::MessageBase(std::string const& cls, std::string const& selector): MessageBase(objc_getClass(cls.c_str()), selector){}

id MessageBase::object(void){
    return this->impl->_object;
}

SEL MessageBase::selector(void){
    return this->impl->_selector;
}

template class Base::Object<MessageBase>;
