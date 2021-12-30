//============================================================================
// Name        : lval_box.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

class BBwidget {
public:
    virtual ~BBwidget() {}
};

class BBslider : public BBwidget {
public:
    virtual ~BBslider() {}
};

class Ival_box {
public:
    virtual ~Ival_box() {};
};

class Ival_slider : public Ival_box {
public:
    virtual ~Ival_slider() {}
};

class BB_ival_slider : public Ival_slider, protected BBslider {
    // ...
};

void f(BB_ival_slider* p) {
    //cross cast
    Ival_slider* pi1 = p;                               // OK
    Ival_slider* pi2 = dynamic_cast<Ival_slider*>(p);   // OK

    //BBslider* pbb1 = p;
    //BBslider* pbb2 = dynamic_cast<BBslider*>(p);
}

void g(Ival_box* pb) {
    BB_ival_slider* pd1 = dynamic_cast<BB_ival_slider*>(pb); // OK
//    BB_ival_slider* pd2 = pb;                                // ERROR
}

int main() {
    BB_ival_slider* b = new BB_ival_slider;
    f(b);
    g(b);
	return 0;
}
