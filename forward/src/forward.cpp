//============================================================================
// Name        : forward.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Section 28.6.3 Forwarding
//============================================================================

#include <iostream>
#include <utility>
#include <string>

template<typename F, typename ... T>
void call(F&& f, T&&... t)
{
    f(std::forward<T>(t)...);
}

void g0()
{
    std::cout << "g0()\n";
}

template<typename T>
void g1(const T& t)
{
    std::cout << "g1(): " << t << '\n';
}

void g1d(double t)
{
    std::cout << "g1d(): " << t << '\n';
}

template<typename T, typename T2>
void g2(const T& t, T2&& t2)
{
    std::cout << "g2(): " << t << ' ' << t2 << '\n';
}

void test()
{
    call(g0);
    //call(g1);                       //error : too few arguments

    call(g1<int>,1);
    call(g1<const char*>,"hello");
    call(g1<double>,1.2);
    call(g1d,1.2);
    //call(g1d,"No way!");            // error : wrong argument type for g1d()
    //call(g1d,1.2,"I can't count");  // error : too many arguments for g1d()
    call(g2<double, std::string>,1,"world!");
    int i = 99;                     // testing with lvalues
    const char* p = "Trying";
    call(g2<double, std::string>,i,p);
    call([]()     { std::cout <<"l1()\n"; });
    call([](int i){ std::cout <<"l0(): " << i << "\n";},17);
    call([i]()    { std::cout <<"l1(): " << i << "\n"; });
}

int main() {
    test();

	return 0;
}
