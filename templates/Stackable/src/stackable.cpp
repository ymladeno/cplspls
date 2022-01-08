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

template<typename T>
constexpr bool Regular() {
    return true;
}

template<typename T,int N>
constexpr bool Stackable()                          // T is regular and N elements of T can fit on a small stack
{
    return Regular<T>() && sizeof(T)*N<=stack_limit;
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

int main() {
    fct<double, 100>();
	return 0;
}
