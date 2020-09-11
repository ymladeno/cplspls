//============================================================================
// Name        : template_copy.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

template<typename T>
void copy(T* p, const T* q, int n)
{
    if (std::is_pod<T>::value)
        memcpy(p,q,n); // use optimized memory copy
    else
        for (int i=0; i!=n; ++i)
            p[i] = q[i]; // copy individual values
}

int main() {

	return 0;
}
