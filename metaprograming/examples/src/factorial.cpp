//============================================================================
// Name        : template_factorial.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Section 28.3.2 Iteration and Recursion
//============================================================================

#include <iostream>

////////////////////
// Template variant
////////////////////

template<int N>
constexpr int fac()
{
    return N*fac<N-1>();
}

template<>
constexpr int fac<1>()
{
    return 1;
}

constexpr int x5 = fac<5>();

////////////////////
// constexpr variant
////////////////////

constexpr int fac(int i)
{
    return (i<2)?1:i*fac(i-1);
}

constexpr int x6 = fac(5);

////////////////////
// class variant
////////////////////
template<int N>
struct Fac {
    static const int value = N*Fac<N-1>::value;
};

template<>
struct Fac<1> {
    static const int value = 1;
};

constexpr int x7 = Fac<5>::value;

int main() {
    std::cout << x5 << std::endl;
    std::cout << x6 << std::endl;
    std::cout << x7 << std::endl;
    return 0;
}
