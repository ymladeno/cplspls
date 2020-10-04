//============================================================================
// Name        : template_complex.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

//If a function template’s argument has been determined by template
//argument deduction, that argument cannot also have promotions, standard
//conversions, or user-defined conversions applied

template<typename T>
class complex {
    T re, im;
public:
    complex(const T& r = T{}, const T& i = T{})
        : re{ r }, im{ i } {}

    complex(const complex&);                //default copy ctor
    template<typename X>
    complex(const complex<X>&);             // conversion from complex<X> to complex<T>

    complex& operator=(const complex&);
    complex& operator=(const T&);
    complex& operator+=(const T& x);

    // needs access to representation
    //complex& operator+=(const complex a);

    template<typename X>
    complex<T>& operator=(const complex<X>&);
    template<typename X>
    complex<T>& operator+=(const complex<X>& x);

    constexpr T real() { return re; }
    constexpr T imag() { return im; }
};

template<>
class complex<float> {
    float re, im;
public:
    constexpr complex() : re{}, im{} {}
    complex& operator=(float);
    complex& operator+=(float);
    complex& operator=(const complex&);
};

template<>
class complex<long double> {
    long double re, im;
public:
    constexpr complex() : re{}, im{} {}
    complex& operator=(long double);
    complex& operator+=(long double);
    complex& operator=(const complex&);
};

template<>
class complex<double> {
    double re{}, im{};
public:
    constexpr complex(double r = 0.0, double i = 0.0) : re{r}, im{i} {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    constexpr complex(const complex<float>&) : re{1000}, im{22} {};
    explicit constexpr complex(const complex<long double>& c) : re {}, im{} {}
    complex& operator+=(const complex a) {
        re += a.real();
        im += a.imag();
        return *this;
    }

    constexpr double real() const { return re; }
    constexpr double imag() const { return im; }
};

template<typename Scalar>
complex<Scalar> operator+(complex<Scalar> a, complex<Scalar> b)
{
    return a += b;                                  // access representation through +=
}

template<typename Scalar>
complex<Scalar> operator+(complex<Scalar> a, int b)
{
    return a+=b;                                    // access representation through +=
}

template<typename Scalar>
complex<Scalar> operator+(int a, complex<Scalar> b)
{
    return b+=a;                                    // access representation through +=
}

int main()
{
    constexpr complex<double> cd{ complex<float>{} };
    complex<double> x {1.0, 3.0};
    complex<double> y {2.0, 6.0};
    complex<double> z {5.0, 8.0};

    complex<double> r1 {x+y+z};
    complex<double> r2 {x};
    constexpr complex<double> r3{ complex<long double>{} };

    r2+=y;
    r2+=z;

    auto c1 = x+y; // calls operator+(complex,complex)
    auto c2 = x+2; // calls operator+(complex,double)
    auto c3 = 2+x; // calls operator+(double,complex)
    auto c4 = 2+3; // built-in integer addition
}
