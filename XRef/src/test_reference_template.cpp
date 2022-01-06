//============================================================================
// Name        : test_reference_template.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Section 23.5.2.1
//============================================================================

#include <iostream>
#include <memory>

template<typename TT, typename A>
std::unique_ptr<TT> make_unique(int i, A&& a) // simple variant of make_shared (§34.3.2)
{
    return std::unique_ptr<TT>{new TT{i,std::forward<A>(a)}};
}

template<typename T>
class Xref {
public:
    Xref(int i, T* p)                       // store a pointer: Xref is the owner
    :index{i}, elem{p}, owned{true}
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Xref(int i, T& r)                       // store a pointer to r, owned by someone else
    :index{i}, elem{&r}, owned{false}
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Xref(int i, T&& r)                      // move r into Xref, Xref is the owner
    :index{i}, elem{new T{move(r)}}, owned{true}
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    ~Xref()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        if(owned) delete elem;
    }
// ...
private:
    int     index;
    T*      elem;
    bool    owned;
};

int main() {

    std::string x {"There and back again"};
    Xref<std::string> r1 {7,"Here"};                    // r1 owns a copy of string{"Here"}
    Xref<std::string> r2 {9,x};                         // r2 just refers to x
    Xref<std::string> r3 {3,new std::string{"There"}};  // r3 owns the string{"There"}

    auto p1 = make_unique<Xref<std::string>>(7,"Here");
    auto p2 = make_unique<Xref<std::string>>(9,x);

	return 0;
}
