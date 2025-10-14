#pragma once
#include <algorithm>
#include <internals/Defines.hpp>

namespace Base{
template <typename _T>
class Object {
public:
    Object(void);
    ~Object(void);
    template<typename A1, typename... A2>
    Object(A1 a1, A2... a2);
    Object(Object<_T> const& o);
    Object(Object<_T>&& o);
    Object& operator=(Object<_T> const& o);
    friend void swap(Object<_T>& o1, Object<_T>& o2);
private:
    friend _T;
    class IMPL;
    IMPL* impl;
};
}

template<typename _T>
Base::Object<_T>::Object(void): impl(new IMPL()){}

template<typename _T>
Base::Object<_T>::~Object(void){
    delete this->impl;
}

template <typename _T>
template <typename A1, typename... A2>
Base::Object<_T>::Object(A1 a1, A2... a2) :
    impl(new IMPL(a1, a2...)){}

template<typename _T>
Base::Object<_T>::Object(Object const& o): impl(new IMPL(*(o.impl))){}

template<typename _T>
Base::Object<_T>::Object(Object&& o): impl(std::move(o)){
    o.impl = nullptr;
}

template<typename _T>
Base::Object<_T>& Base::Object<_T>::operator=(const Object<_T> &o){
    this->impl = o.impl;
    return *this;
}

template<typename _T>
void swap(Base::Object<_T>& o1, Base::Object<_T>& o2){
    std::swap(o1.impl, o2.impl);
}
