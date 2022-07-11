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
    void operator()(int x) { std::cout << "X" << x <<"!\n"; }
};

struct Y {
    void operator()(int y) { std::cout << "Y" << y <<"!\n"; }
};

int main() {
    Conditional<true,X,Y> z;
    z(7);

    Conditional<(sizeof(int)>4),X,Y>{}(7);
    std::conditional<(sizeof(int)>4),X,Y>::type{}(7);
    std::cout << sizeof(int) << "\n";
	return 0;
}
