#pragma once
#include <internals/BaseObject.hpp>
#include <internals/Defines.hpp>
#include <type_traits>

class MessageBase : public Base::Object<MessageBase>{
public:
    using Base::Object<MessageBase>::impl;
    MessageBase(id cls, SEL selector);
    MessageBase(id cls, std::string const& selector);
    MessageBase(Class cls, std::string const& selector);
    MessageBase(Class cls, SEL selector);
    MessageBase(std::string const&, std::string const& selector);
    
    id object(void);
    SEL selector(void);
};

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

template <class _Ret>
class Message : public MessageBase {
public:
    Message(id cls, SEL selector): MessageBase(cls, selector){}
    Message(id cls, std::string const& selector): MessageBase(cls, selector){}
    Message(Class cls, std::string const& selector) : MessageBase(cls, selector){}
    Message(Class cls, SEL selector) : MessageBase(cls, selector){}
    Message(std::string const& cls, std::string const& selector) : MessageBase(cls, selector){}
    template <class... _Args>
    _Ret send(_Args... args) {
        if constexpr(std::is_floating_point_v<_Ret>) {
            return (( _Ret (*)(id, SEL, _Args...) )objc_msgSend_fpret)
                    (this->object(), this->selector(), args...);
        } else if constexpr(std::is_void_v<_Ret>) {
            (( void (*)(id, SEL, _Args...) )objc_msgSend)
                    (this->object(), this->selector(), args...);
        } else if constexpr(std::is_class_v<_Ret> || std::is_pointer_v<_Ret>) {
            using Fn = _Ret (*)(id, SEL, _Args...);
            return ((Fn)objc_msgSend)(this->object(), this->selector(), args...);
        } else {
            using Fn = _Ret (*)(id, SEL, _Args...);
            return ((Fn)objc_msgSend)(this->object(), this->selector(), args...);
        }
    }
};

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
