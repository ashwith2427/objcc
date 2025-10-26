#pragma once
#include <internals/NSDefines.hpp>
#include <internals/BaseObject.hpp>
#include <string>
#include <internals/NSEnums.hpp>

namespace Ref{
class Object;
}

namespace Abstract{
template <class _T>
class Object{
public:
    Object(void) = default;
    Object(Object const& o) = default;
    ~Object(void){}
    
    friend _T;
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
    NSUInteger      hash( void )                            const;
    id              performSelector( SEL sel )                   ;
    id              performSelector( SEL sel, id o1 )            ;
    id              performSelector( SEL sel, id o1, id o2 )     ;
    bool            isProxy( void )                         const;
    id              retain( void )                               ;
    void            release( void )                              ;
    NSUInteger      retainCount( void )                     const;
    id              autorelease( void )                     const;
    void*           zone( void )                            const;
};
}

template <class _T>
Class Abstract::Object<_T>::getClass() const{
    return static_cast<const _T*>(this)->getClass();
}

template <class _T>
Class Abstract::Object<_T>::superclass() const{
    return static_cast<const _T*>(this)->superclass();
}

template <class _T>
bool Abstract::Object<_T>::isEqual(const Ref::Object &o) const{
    return static_cast<const _T*>(this)->isEqual(o);
}


template <class _T>
id Abstract::Object<_T>::self(void) const{
    return static_cast<const _T*>(this)->self();
}

template <class _T>
bool Abstract::Object<_T>::isKindOfClass(Class cls) const{
    return static_cast<const _T*>(this)->isKindOfClass(cls);
}

template <class _T>
bool Abstract::Object<_T>::isMemberOfClass(Class cls) const{
    return static_cast<const _T*>(this)->isMemberOfClass(cls);
}

template <class _T>
bool Abstract::Object<_T>::respondsToSelector(SEL sel) const{
    return static_cast<const _T*>(this)->respondsToSelector(sel);
}

template <class _T>
bool Abstract::Object<_T>::conformsToProtocol(void *protocol) const{
    return static_cast<const _T*>(this)->conformsToProtocol(protocol);
}

template <class _T>
std::string Abstract::Object<_T>::description() const{
    return static_cast<const _T*>(this)->description();
}

template <class _T>
std::string Abstract::Object<_T>::debugDescription() const{
    return static_cast<const _T*>(this)->debugDescription();
}

template <class _T>
NSUInteger  Abstract::Object<_T>::hash() const{
    return static_cast<const _T*>(this)->hash();
}

template <class _T>
id Abstract::Object<_T>::performSelector(SEL sel){
    return static_cast<const _T*>(this)->performSelector(sel);
}

template <class _T>
id Abstract::Object<_T>::performSelector(SEL sel, id o1){
    return static_cast<const _T*>(this)->performSelector(sel, o1);
}

template <class _T>
id Abstract::Object<_T>::performSelector(SEL sel, id o1, id o2){
    return static_cast<const _T*>(this)->performSelector(sel, o1, o2);
}

template <class _T>
bool Abstract::Object<_T>::isProxy() const{
    return static_cast<const _T*>(this)->isProxy();
}

template <class _T>
id Abstract::Object<_T>::retain(){
    return static_cast<const _T*>(this)->retain();
}

template <class _T>
NSUInteger Abstract::Object<_T>::retainCount() const{
    return static_cast<const _T*>(this)->retainCount();
}

template <class _T>
void Abstract::Object<_T>::release(){
    return static_cast<const _T*>(this)->release();
}

template <class _T>
id Abstract::Object<_T>::autorelease() const{
    return static_cast<const _T*>(this)->autorelease();
}

template <class _T>
void* Abstract::Object<_T>::zone() const{
    return static_cast<const _T*>(this)->zone();
}
