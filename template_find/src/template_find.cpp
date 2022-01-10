//============================================================================
// Name        : template_find.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

template<typename A, typename B>
constexpr bool Equality_comparable()
{
    return true;
};

template<typename T>
constexpr bool Input_iterator() {
    return true;
}

template<typename T>
using Value_type = T;

template<typename Iter, typename Val>
Iter find(Iter b, Iter e, Val x)
{
    static_assert(Input_iterator<Iter>(),"find() requires an input iterator");
    static_assert(Input_iterator<Iter>(),"find() requires an input iterator");
    static_assert(Equality_comparable<Value_type<Iter>,Val>(), "find()'s iterator and value arguments must match");

    while (b!=e) {
        if (*b==x) return b;
        ++b;
    }

    return b;
}

int main() {
    std::vector<int> vi{10,101,202,303};
    auto vt = find(vi.cbegin(), vi.cend(), 101);
    std::cout << *vt;

    std::list<int> li{10,101,202,303};
    auto lt = find(li.cbegin(), li.cend(), 101);
    std::cout << *lt;
	return 0;
}
