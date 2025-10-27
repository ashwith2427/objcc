#include <internals/Message.hpp>
#include <string>
#include <iostream>

template <>
class Base::Object<MessageBase>::IMPL{
public:
    IMPL(void);
    ~IMPL(void);
    IMPL(IMPL const& o);
    IMPL(id cls, std::string const& selector, Class objc_class);
    IMPL(id cls, SEL selector, Class objc_class);
    id _object;
    SEL _selector;
    Class _class;
};

Base::Object<MessageBase>::IMPL::IMPL(void):_object(nullptr), _selector(nullptr), _class(nullptr){}

Base::Object<MessageBase>::IMPL::~IMPL(void){}

Base::Object<MessageBase>::IMPL::IMPL(IMPL const& o): _object(o._object), _selector(o._selector), _class(o._class){}

Base::Object<MessageBase>::IMPL::IMPL(id cls, std::string const& selector, Class obj_class): _object(cls), _selector(sel_getUid(selector.c_str())), _class(obj_class){}

Base::Object<MessageBase>::IMPL::IMPL(id cls, SEL selector, Class objc_class):
    _object(cls), _selector(selector), _class(objc_class){}


MessageBase::MessageBase(id cls, SEL selector) : Base::Object<MessageBase>(cls, selector, object_getClass(cls)){
}

MessageBase::MessageBase(id cls, std::string const& selector): Base::Object<MessageBase>(cls, selector, object_getClass(cls)){}

MessageBase::MessageBase(Class cls, std::string const& selector): Base::Object<MessageBase>(reinterpret_cast<id>(cls), selector, cls){}

MessageBase::MessageBase(Class cls, SEL selector):
    Base::Object<MessageBase>(reinterpret_cast<id>(cls), selector, cls){}

MessageBase::MessageBase(std::string const& cls, std::string const& selector): MessageBase(objc_getClass(cls.c_str()), selector){}

id MessageBase::object(void){
    return this->impl->_object;
}

SEL MessageBase::selector(void){
    return this->impl->_selector;
}

Class MessageBase::objc_class(void){
    return this->impl->_class;
}

template class Base::Object<MessageBase>;
