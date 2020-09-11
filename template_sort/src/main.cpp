//============================================================================
// Name        : template_sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <utility>

// Shell sort (Knuth, Vol. 3, pg. 84)
template<typename T, typename Compare = std::less<T>>
void mysort(std::vector<T>& v) // definition
{
    Compare cmp;
    const size_t n = v.size();
    for (int gap=n/2; 0<gap; gap/=2)
        for (int i=gap; i<n; i++)
            for (int j=i-gap; 0<=j; j-=gap)
                if (cmp(v[j+gap], v[j])) {              // swap v[j] and v[j+gap]
                    std::swap(v[j],v[j+gap]);
                }
}

template<typename T>
void print_all(std::vector<T>& v)
{
    for(const auto& i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> vi{1,5,10,2};
    print_all(vi);
    mysort(vi);
    print_all(vi);

	return 0;
}
