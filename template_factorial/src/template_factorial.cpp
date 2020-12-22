//============================================================================
// Name        : template_factorial.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Section 28.3.2 Iteration and Recursion
//============================================================================

#include <iostream>

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

// Alternative
constexpr int fac(int i)
{
    return (i<2)?1:i*fac(i-1);
}

constexpr int x6 = fac(6);

int main() {
    std::cout << x5 << std::endl;
    std::cout << x6;
	return 0;
}
