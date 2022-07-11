//============================================================================
// Name        : template_select.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

class Nil {};

struct X {
    void operator()(int x) { std::cout << "X" << x <<"!\n"; }
};

struct Y {
    void operator()(int y) { std::cout << "Y" << y <<"!\n"; }
};

template<int I, typename T1 =Nil, typename T2 =Nil, typename T3 =Nil, typename T4 =Nil>
struct sselect;

// Specializations for 0-3:
template<typename T1, typename T2, typename T3, typename T4>
struct sselect<0,T1,T2,T3,T4> { using type = T1; }; // specialize for N==0

template<typename T1, typename T2, typename T3, typename T4>
struct sselect<1,T1,T2,T3,T4> { using type = T2; }; // specialize for N==1

template<typename T1, typename T2, typename T3, typename T4>
struct sselect<2,T1,T2,T3,T4> { using type = T3; }; // specialize for N==2

template<typename T1, typename T2, typename T3, typename T4>
struct sselect<3,T1,T2,T3,T4> { using type = T4; }; // specialize for N==3

template<int I, typename T1 =Nil, typename T2 =Nil, typename T3 =Nil, typename T4 =Nil>
using Select = typename sselect<I,T1,T2,T3,T4>::type;

template<unsigned N, typename... Cases>             // general case; never instantiated
struct nselect;

template<unsigned N, typename T, typename... Cases>
struct nselect<N,T,Cases...> : nselect<N-1, Cases...> {
};

template<typename T, typename... Cases>            // final case: N==0
struct nselect<0,T,Cases...> {
    using type = T;
};

template<unsigned N, typename... Cases>
using NSelect = typename nselect<N,Cases...>::type;

int main() {
    Select<1,int,X,double,char> x;
    x(7);
    NSelect<2,int,X,Y,char> y;
    y(7);
	return 0;
}
