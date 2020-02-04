//============================================================================
// Name        : final.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>


template<typename F>
struct Final_action {
    Final_action(F f) : clean{f} {}
    ~Final_action() {clean();}
    F clean;
};

template<typename F>
Final_action<F> final(F f) {
    return Final_action<F>(f);
}

int main()
{
    auto act = final([](){std::cout << "cleaning\n";});

    std::cout << "Executing\n";
}
