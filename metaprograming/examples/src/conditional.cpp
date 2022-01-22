//============================================================================
// Name        : template_std_conditional.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Section 28 Metaprogramming
//               Implementation of std::conditional
//============================================================================

#include <iostream>

template<bool C, typename T, typename F> // general template
struct conditional {
    using type = T;
};

template<typename T, typename F> // specialization for false
struct conditional<false,T,F> {
    using type = F;
};

template<bool B, typename T, typename F>
using Conditional = typename conditional<B,T,F>::type;

struct X {
    void operator()(int x) { std::cout << "X" << x <<"!"; }
};

struct Y {
    void operator()(int y) { std::cout << "Y" << y <<"!"; }
};

int main() {
    Conditional<true,X,Y> z;
    z(7);
	return 0;
}
