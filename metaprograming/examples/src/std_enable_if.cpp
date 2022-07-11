//============================================================================
// Name        : std_enable_if.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <type_traits>

///////////////////////////////
// enable_if implementation
//////////////////////////////
template<bool B, typename T = void>
struct enable_if {
    typedef T type;
};

template<typename T>
struct enable_if<false, T>{};             // no ::type if B==false

template<bool B, typename T = void>
using Enable_if = typename enable_if<B,T>::type;

///////////////////////////////
//Enable_if examples (SFINAE)
//////////////////////////////
struct failure { };                         // represent a failure to declare something

template<typename T>
struct succeeded : std::true_type { };

template<>
struct succeeded<failure> : std::false_type { };

struct Y {};

void f(int i) { std::cout << "f(int)\n"; }
void f(const Y& y) { std::cout << "f(Y)\n"; }

template<typename T>
struct get_f_result {
private:
    template<typename X>
    static auto check(X const& x) -> decltype(f(x));    // can call f(x)

    static failure check(...);                          // cannot call f(x)
public:
    using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_f
: succeeded<typename get_f_result<T>::type> { };

template<typename T>
constexpr bool Has_f()
{
    return has_f<T>::value;
}

template<typename T>
class X {
public:
    Enable_if<Has_f<T>()> use_f(const T& t) {
        f(t);
    }

    // template<typename T1=T>
    // typename std::enable_if<Has_f<T1>()>::type use_f(const T1& t)
    // {
    //     //
    //     f(t);
    //     //
    // }
};

int main() {
    X<int> x{};
    int i{10};
    x.use_f(i);

    X<Y> x1{};
    Y y{};
    x1.use_f(y);

	return 0;
}
