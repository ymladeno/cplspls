//============================================================================
// Name        : template_conversion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

struct Shape {

};

struct Circle : public Shape {

};

// pointer to T
template<typename T>
class Ptr {
    T* p;

public:
    Ptr(T*);

    // copy constructor
    Ptr(const Ptr& x) : p{x.p} {}

    // convert Ptr<T> to Ptr<T2>
    template<typename T2>
    explicit operator Ptr<T2>();
    // ...
};

template<typename T>
    template<typename T2>
        Ptr<T>::operator Ptr<T2>()
        {
            return Ptr<T2>{p};
        }

void f(Ptr<Circle> pc)
{
    // should work
    Ptr<Shape> ps {pc};

    // should give error
    Ptr<Circle> pc2 {ps};
}

int main() {
    Ptr<Circle> pc;
    f(pc);
	return 0;
}
