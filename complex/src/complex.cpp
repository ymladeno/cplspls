//============================================================================
// Name        : complex.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

class complex {
    double re, im;

public:
    complex(double a, double b) : re{a}, im{b} {}
    complex(double a) : re{a}, im{} {}
    // needs access to representation
    complex& operator+=(complex a) {
        re += a.real();
        im += a.imag();
        return *this;
    }
    complex& operator+=(double a) {
        re += a;
        return *this;
    }
    constexpr double real() { return re; }
    constexpr double imag() { return im; }
    // ...
};

complex operator+(complex a, complex b)
{
    return a += b;                          // access representation through +=
}

//complex operator+(complex a, double b)
//{
//    return a += b;                   // access representation through +=
//}
//
//complex operator+(double a, complex b)
//{
//    return b += a;                   // access representation through +=
//}

int main() {
    complex x {1.0, 3.0};
    complex y {2.0, 6.0 };
    complex z {5.0, 8.0 };

    complex r1 {x+y+z};
    complex r2 {x};

    r2+=y;
    r2+=z;

    auto c1 = x+y; // calls operator+(complex,complex)
    auto c2 = x+2; // calls operator+(complex,double)
    auto c3 = 2+x; // calls operator+(double,complex)
    auto c4 = 2+3; // built-in integer addition

	return 0;
}
