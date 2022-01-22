//============================================================================
// Name        : template_copy.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Section 28.2.2
//============================================================================

#include <iostream>
#include <cstring>

template<typename T>
void copy(T* p, const T* q, int n)
{
    if (std::is_pod<T>())
        std::memcpy(p,q,n); // use optimized memory copy
    else
        for (int i=0; i!=n; ++i)
            p[i] = q[i]; // copy individual values
}

int main() {
    auto s = new int[10]{1};
    auto d = new int[10];
    copy(d,s,10);
	return 0;
}
