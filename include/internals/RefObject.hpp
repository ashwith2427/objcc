#pragma once
#include <internals/Object.hpp>
#include <internals/Message.hpp>
#include <functional>
#include <internals/NSEnums.hpp>

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
    template <class _Ret>
    Message<_Ret> message(SEL selector) const{
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
    NSUInteger      hash(void)                              const;
    id              performSelector( SEL sel )                   ;
    id              performSelector( SEL sel, id o1 )            ;
    id              performSelector( SEL sel, id o1, id o2 )     ;
    bool            isProxy( void )                         const;
    id              retain( void )                               ;
    NSUInteger      retainCount( void )                     const;
    void            release( void )                              ;
    id              autorelease( void )                     const;
    void*           zone( void )                            const;
protected:
    Object(std::string const& className);
    Object(std::string const& className, std::function<id(void)> init);
};
}
