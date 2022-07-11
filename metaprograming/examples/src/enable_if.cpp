//============================================================================
// Name        : enable_if.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Section 28.4 enable_if
//============================================================================

#include <iostream>
#include <type_traits>
#include <iterator>

template<bool B, typename T>
using Enable_if = typename std::enable_if<B,T>::type;

template<typename T>
constexpr bool Is_class()
{
    return std::is_class<T>::value;
}

template<typename T>
struct Smart_pointer {
    Smart_pointer(T val) : p{ new T{val}} {}
    T& operator*() { return *p; }                             //return reference to whole object
    template<class T1=T>
    Enable_if<Is_class<T1>(),T1>* operator->() { return p; }  // select a member (for classes only)
private:
    T* p;
};

template<typename Scale>
struct complex {
    Scale real() { return 1.0; }
};

template<class I>
constexpr bool Input_iterator() { return true; }

template<typename T>
class myvector {
public:
    myvector(size_t n, const T& val) {
        std:: cout << __PRETTY_FUNCTION__;
    } // n elements of type T with value val

    template<typename Iter, typename =Enable_if<Input_iterator<Iter>(),Iter>>
            myvector(Iter b, Iter e) {
        std:: cout << __PRETTY_FUNCTION__;
    } // initialize from [b:e)
    // ...
};

void f(Smart_pointer<double> p, Smart_pointer<complex<double>> q)
{
    auto d0 = *p; //OK
    auto c0 = *q; //OK
    auto d1 = q->real(); // OK
    // auto d2 = p->real(); // error : p doesn’t point to a class object
    // ...
}

int main()
{
    myvector<int> i(10, 20);
    // Smart_pointer<double> 
}

