//============================================================================
// Name        : template_conditional.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <type_traits>

struct X {
    void operator()(int x) { std::cout << "X" << x <<"!"; }
};

struct Y {
    void operator()(int y) { std::cout << "Y" << y <<"!"; }
};

template<bool C, typename T, typename F>
using Conditional = typename std::conditional<C,T,F>::type;

template<typename T>
constexpr bool Is_polymorphic() {
    return std::is_polymorphic<T>::value;
}

void f() {
    Conditional<(sizeof(int)>4),X,Y>{}(7);

    using Z = Conditional<(std::is_polymorphic<X>()),X,Y>;
    Z zz;
    zz(8);
}

int main() {
    f();
	return 0;
}
