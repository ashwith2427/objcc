#pragma once
#include <internals/BaseObject.hpp>
#include <internals/Defines.hpp>
#include <type_traits>

class MessageBase : public Base::Object<MessageBase>{
public:
    using Base::Object<MessageBase>::impl;
    MessageBase(id cls, std::string const& selector);
    MessageBase(Class cls, std::string const& selector);
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
    id _object;
    SEL _selector;
};

Base::Object<MessageBase>::IMPL::IMPL(void):_object(nullptr), _selector(nullptr){}

Base::Object<MessageBase>::IMPL::~IMPL(void){}

Base::Object<MessageBase>::IMPL::IMPL(IMPL const& o): _object(o._object), _selector(o._selector){}

Base::Object<MessageBase>::IMPL::IMPL(id cls, std::string const& selector): _object(cls), _selector(sel_registerName(selector.c_str())){}


template <class _Ret, class E = void>
class Message;

namespace Types {
template <class _U>
struct IsFloatRet : public std::integral_constant<bool, std::is_floating_point_v<_U>>{};

template <class _U>
struct IsStructRet : public std::integral_constant<bool, std::is_class_v<_U>>{};

template <class _U>
struct IsVoidRet : public std::integral_constant<bool, std::is_void_v<_U>>{};

template <class _U>
struct IsSimpleRet : public std::integral_constant<bool, !IsFloatRet<_U>::value && !IsStructRet<_U>::value && !IsVoidRet<_U>::value>{};
}

template <class _Ret>
class Message<_Ret, std::enable_if_t<Types::IsVoidRet<_Ret>::value>> : public MessageBase {
public:
    Message(id cls, std::string const& selector): MessageBase(cls, selector){}
    Message(Class cls, std::string const& selector) : MessageBase(cls, selector){}
    Message(std::string const& cls, std::string const& selector) : MessageBase(cls, selector){}
    
    template <class... _Args>
    void send(_Args... args){
        objc_msgSend(this->object(), this->selector(), std::forward<_Args>(args)...);
    }
};


template <class _Ret>
class Message<_Ret, std::enable_if_t<Types::IsFloatRet<_Ret>::value>> : public MessageBase{
public:
    Message(id cls, std::string const& selector): MessageBase(cls, selector){}
    Message(Class cls, std::string const& selector) : MessageBase(cls, selector){}
    Message(std::string const& cls, std::string const& selector) : MessageBase(cls, selector){}
    
    template <class... _Args>
    _Ret send(_Args... args){
        return reinterpret_cast<_Ret>(objc_msgSend_fpret(this->object(), this->selector(), std::forward<_Args>(args)...));
    }
};


template <class _Ret>
class Message<_Ret, std::enable_if_t<Types::IsSimpleRet<_Ret>::value && (sizeof(_Ret) < sizeof(id))>> : public MessageBase{
public:
    Message(id cls, std::string const& selector): MessageBase(cls, selector){}
    Message(Class cls, std::string const& selector) : MessageBase(cls, selector){}
    Message(std::string const& cls, std::string const& selector) : MessageBase(cls, selector){}
    
    template <class... _Args>
    _Ret send(_Args... args){
        uintptr_t p;
        p = reinterpret_cast<uintptr_t>(objc_msgSend(this->object(), this->selector(), std::forward<_Args>(args)...));
        return static_cast<_Ret>(p);
    }
};

template <class _Ret>
class Message<_Ret, std::enable_if_t<Types::IsSimpleRet<_Ret>::value && (sizeof(_Ret) >= sizeof(id))>> : public MessageBase{
public:
    Message(id cls, std::string const& selector): MessageBase(cls, selector){}
    Message(Class cls, std::string const& selector) : MessageBase(cls, selector){}
    Message(std::string const& cls, std::string const& selector) : MessageBase(cls, selector){}
    
    template <class... _Args>
    _Ret send(_Args... args){
        return reinterpret_cast<_Ret>(objc_msgSend(this->object(), this->selector(), std::forward<_Args>(args)...));
    }
};


template <class _Ret>
class Message<_Ret, std::enable_if_t<Types::IsStructRet<_Ret>::value>> : public MessageBase{
public:
    Message(id cls, std::string const& selector): MessageBase(cls, selector){}
    Message(Class cls, std::string const& selector) : MessageBase(cls, selector){}
    Message(std::string const& cls, std::string const& selector) : MessageBase(cls, selector){}
    
    template <class... _Args>
    _Ret send(_Args... args){
        typedef _Ret(*StructRet)(id, SEL, ...);
        return reinterpret_cast<StructRet>(objc_msgSend)(this->object(), this->selector(), std::forward<_Args>(args)...);
    }
};

MessageBase::MessageBase(id cls, std::string const& selector): Base::Object<MessageBase>(cls, selector){}

MessageBase::MessageBase(Class cls, std::string const& selector): Base::Object<MessageBase>(reinterpret_cast<id>(cls), selector){}

MessageBase::MessageBase(std::string const& cls, std::string const& selector): MessageBase(objc_getClass(cls.c_str()), selector){}
id MessageBase::object(void){
    return this->impl->_object;
}

SEL MessageBase::selector(void){
    return this->impl->_selector;
}
