//============================================================================
// Name        : template_find.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

//*******************************//
constexpr int stack_limit = 2048;

template<typename T,int N>
constexpr bool Stackable()                          // T is regular and N elements of T can fit on a small stack
{
    return Regular<T>() && sizeof(T)∗N<=stack_limit;
}

template<typename T, int N>
struct Buffer {
    // ...
};

template<typename T, int N>
void fct()
{
    static_assert(Stackable<T,N>(),"fct() buffer won't fit on stack");
    Buffer<T,N> buf;
    // ...
}

//*******************************//

template<typename Val>
struct Forward {                        // for checking find()
    Forward();
    Forward(const Forward&);
    Forward operator=(const Forward&);
    bool operator==(const Forward&);
    bool operator!=(const Forward&);
    void operator++();
    Val& operator*();                   // simplified: does not handle a proxy for Val
};

template<typename Val>
using Value_type<Forward<Val>> = Vap;

void f()
{
    Forward<int> p = find(Forward<int>{},Forward<int>{},7);
}

//*******************************//
template<typename A, typename B>
constexpr bool Equality_comparable(A a, B b)
{
    return Common<T, U>()
            && Totally_ordered<T>()
            && Totally_ordered<U>()
            && Totally_ordered<Common_type<T,U>>()
            && Has_less<T,U>() &&           Boolean<Less_result<T,U>>()
            && Has_less<U,T>() &&           Boolean<Less_result<U,T>>()
            && Has_greater<T,U>() &&        Boolean<Greater_result<T,U>>()
            && Has_greater<U,T>() &&        Boolean<Greater_result<U,T>>()
            && Has_less_equal<T,U>() &&     Boolean<Less_equal_result<T,U>>()
            && Has_less_equal<U,T>() &&     Boolean<Less_equal_result<U,T>>()
            && Has_greater_equal<T,U>() &&  Boolean<Greater_equal_result<T,U>>()
            && Has_greater_equal<U,T>() &&  Boolean<Greater_equal_result<U,T>>();
};

template<typename Iter, typename Val>
Iter find(Iter b, Iter e, Val x)
{
    static_assert(Input_iterator<Iter>(),"find() requires an input iterator");
    static_assert(Equality_comparable<Value_type<Iter>,Val>(), "find()'s iterator and value arguments must match");

    while (b!=e) {
        if (*b==x) return b;
        ++b;
    }

    return b;
}

int main() {

	return 0;
}
