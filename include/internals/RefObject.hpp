#pragma once
#include <internals/Object.hpp>
#include <internals/Message.hpp>

#define BASE_TEMPLATE(_class, _base)                                        \
    protected:                                                              \
    _class(std::string const& className): _base(className){}                \
    _class(std::string const& className, std::function<id(void)> init): _base(className, init){}                                            \
    public:                                                                 \
    _class(id object) : _base(object){}                                     \
    _class(_class const& o) : _base(std::forward<_class const&>(o)){}       \
    _class(_class&& o) : _base(std::forward<_class&&>(o)){}                 \
    ~_class(void){}                                                         \
    _class& operator=(_class o){                                            \
        _base::operator=(o);                                                \
        return *this;                                                       \
    }

namespace Ref{
class Object: public Base::Object<Object>, public Abstract::Object<Object> {
public:
    Object  (id object);
    ~Object (void);
    Object  (Object const& o);
    Object  (Object&& o);
    Object& operator=(Object o);
    bool    operator==(Object const& o);
    bool    operator!=(Object const& o);
    bool    operator==(id object);
    bool    operator!=(id object);
    operator id(void) const;
    template <class _Ret>
    Message<_Ret> message(std::string const& selector) const{
        return Message<_Ret>(*(this), selector);
    }
    
    using Base::Object<Object>::impl;
    Class           getClass(void)                          const;
    Class           superclass(void)                        const;
    bool            isEqual(Ref::Object const& o)           const;
    id              self(void)                              const;
    bool            isKindOfClass( Class cls )              const;
    bool            isMemberOfClass( Class cls )            const;
    bool            respondsToSelector( SEL sel )           const;
    bool            conformsToProtocol( void * protocol )   const;
    std::string     description( void )                     const;
    std::string     debugDescription( void )                const;
    id              performSelector( SEL sel )                   ;
    id              performSelector( SEL sel, id o1 )            ;
    id              performSelector( SEL sel, id o1, id o2 )     ;
    bool            isProxy( void )                         const;
    id              retain( void )                               ;
    void            release( void )                              ;
    id              autorelease( void )                     const;
    void*           zone( void )                            const;
protected:
    Object(std::string const& className);
    Object(std::string const& className, std::function<id(void)> init);
};
}

template <>
class Base::Object<Ref::Object>::IMPL{
public:
    IMPL    (void);
    ~IMPL   (void);
    IMPL    (IMPL const& o);
    IMPL    (id object);
    
    std::string _className;
    id          _object;
    Class       _class;
};

Base::Object<Ref::Object>::IMPL::IMPL(void): _className(""), _object(nullptr), _class(nullptr){}

Base::Object<Ref::Object>::IMPL::IMPL(id object): IMPL(){
    if(object){
        this->_class = object_getClass(object);
        this->_object = object;
        this->_className = class_getName(this->_class);
        this->_object = Message<id>(this->_object, "retain").send();
    }
}

Base::Object<Ref::Object>::IMPL::~IMPL(void){
    Message<void>(this->_object, "release").send();
}

Base::Object<Ref::Object>::IMPL::IMPL(IMPL const& o): _className(o._className), _object(o._object), _class(o._class){
    this->_object = Message<id>(_object, "retain").send();
}

Ref::Object::Object(id object): Base::Object<Ref::Object>(object), Abstract::Object<Ref::Object>(){}

Ref::Object::~Object(void){}

Ref::Object::Object(std::string const& className):
            Ref::Object(
                className,
                        [=, this]{
                            return this->message<id>("init").send();
                        }){}
Ref::Object::Object(std::string const& className, std::function<id(void)> init):
    Base::Object<Ref::Object>(),
    Abstract::Object<Object>(){
        this->impl->_className = className;
        this->impl->_class = objc_getClass(className.c_str());
        this->impl->_object = Message<id>(impl->_class, "alloc").send();
        this->impl->_object = init();
}

Ref::Object::Object(Ref::Object const& o): Base::Object<Object>(std::forward<Base::Object<Ref::Object> const&>(o)){}

Ref::Object::Object(Ref::Object&& o): Base::Object<Object>(std::forward<Base::Object<Ref::Object> const&&>(o)){}

Ref::Object& Ref::Object::operator=(Object o){
    std::swap(this->impl->_object, o.impl->_object);
    return *this;
}

bool Ref::Object::operator==(Ref::Object const& o){
    return this->message<bool>("isEqual:").send<id>(o);
}
bool Ref::Object::operator!=(Ref::Object const& o){
    return !operator==(o);
}
bool Ref::Object::operator==(id object){
    return this->message<bool>("isEqual:").send(object);
}
bool Ref::Object::operator!=(id object){
    return !operator==(object);
}

Ref::Object::operator id(void) const{
    return this->impl->_object;
}

Class Ref::Object::getClass(void) const{
    return this->message<Class>("class").send();
}
Class Ref::Object::superclass(void) const{
    return this->message<Class>("superclass").send();
}
bool Ref::Object::isEqual(Ref::Object const& o) const{
    return this->message<bool>("isEqual:").send<id>(o);
}
id Ref::Object::self(void) const{
    return this->message<id>("self").send();
}
bool Ref::Object::isKindOfClass(Class cls) const{
    return this->message<bool>("isKindOfClass:").send(cls);
}
bool Ref::Object::isMemberOfClass(Class cls) const{
    return this->message<bool>("isMemberOfClass:").send(cls);
}
bool Ref::Object::respondsToSelector(SEL sel) const{
    return this->message<bool>("respondsToSelector:").send(sel);
}
bool Ref::Object::conformsToProtocol(void* protocol) const{
    return this->message<bool>("conformsToProtocol:").send(protocol);
}
std::string Ref::Object::description(void) const{
    return "NOT IMPLEMENTED";
}
std::string Ref::Object::debugDescription(void) const{
    return "NOT IMPLEMENTED";
}
id Ref::Object::performSelector(SEL sel){
    return this->message<id>("performSelector:").send(sel);
}
id Ref::Object::performSelector(SEL sel, id o1){
    return this->message<id>("performSelector:withObject:").send(sel, o1);
}
id Ref::Object::performSelector(SEL sel, id o1, id o2){
    return this->message<id>("performSelector:withObject:").send(sel, o1, o2);
}
bool Ref::Object::isProxy(void) const{
    return this->message<bool>("isProxy").send();
}
id Ref::Object::retain(void){
    return this->message<id>("retain").send();
}
void Ref::Object::release(void){
    this->message<void>("release").send();
}
id Ref::Object::autorelease(void) const{
    return this->message<id>("autorelease").send();
}
void* Ref::Object::zone(void) const{
    return this->message<void*>("zone").send();
}
