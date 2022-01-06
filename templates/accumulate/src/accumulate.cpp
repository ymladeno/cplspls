//============================================================================
// Name        : template_sum.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>
#include <functional>

template<typename Iter, typename Val, typename Oper = std::less<>>
Val accumulate(Iter first, Iter last, Val s, Oper op = Oper{})
{
    while (first!=last) {
        s = op(s,*first);
        ++first;
    }
    return s;
}

int main() {
    double ad[] = {1,2,3,4};
    double s1 = accumulate(ad, ad+4, 0.0);
    std::cout << s1 << "\n";
    double s2 = accumulate(ad, ad+4, 0.0, std::plus<double>{});
    std::cout << s2 << "\n";
    double s3 = accumulate(ad, ad+4, 1.0, std::multiplies<double>{});
    std::cout << s3 << "\n";

	return 0;
}
