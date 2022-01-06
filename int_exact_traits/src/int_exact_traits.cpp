//============================================================================
// Name        : int_exact_traits.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Section 23.6 Template aliases
//============================================================================

#include <iostream>

template<int>
struct int_exact_traits {                               // idea: int_exact_traits<N>::type is a type with exactly N bits
    using type = int;
};

template<>
struct int_exact_traits<8> {
    using type = char;
};

template<>
struct int_exact_traits<16> {
    using type = short;
};

template<int N>
using int_exact = typename int_exact_traits<N>::type;   // define alias for convenient notation


int main() {
    int_exact<8> a = 7; // int_exact<8> is an int with 8 bits
    std::cout << "As a char: " << a << "\n";
    std::cout << "As a int: " << static_cast<int>(a) << "\n";
	return 0;
}
