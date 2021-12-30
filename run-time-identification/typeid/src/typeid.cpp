//============================================================================
// Name        : typeid.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>

// For none polymorphic types the result is determined at compile time

struct Poly {                   // polymorphic base class
    virtual void f() {}
    virtual ~Poly() {}
};

struct Non_poly { /* ... */ };                  // no virtual functions

struct D1
: Poly { /* ... */ };

struct D2
: Non_poly { /* ... */ };

void f(Non_poly& npr, Poly& pr)
{
    std::cout << typeid(npr).name() << '\n';     // writes something like "Non_poly"
    typeid(pr);
    std::cout << typeid(pr).name() << '\n';      // name of Poly or a class derived from Poly
}

void g()
{
    D1 d1;      //Poly
    D2 d2;      //Non_poly
    f(d2,d1);   // writes "Non_poly D1"
    f(*(static_cast<Non_poly*>(nullptr)),*(static_cast<Poly*>(nullptr))); // oops!
}

int main() {

    try {
        g();
    }
    catch(std::exception& e) {
        std::cout << "ups" << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "Oho\n";
    }
	return 0;
}
