/*
 * vector.cpp
 *
 *  Created on: May 12, 2019
 *      Author: osboxes
 */

#include <algorithm>

template<class T, class A>
vector<T,A>::vector(size_t n, const T& val, const A& a) : vb{a,n} {
	uninitialized_fill(vb.elem, vb.elem+n, val);
}

template<class T, class A>
vector<T,A>& vector<T,A>::operator =(const vector& a) {
    if (capacity() < a.size()) {
        vector temp{a};
        swap(*this, temp);
        return *this;
    }

    if (this == &a) return *this;

    size_t sz   = size();
    size_t asz  = a.size();
    vb.alloc    = a.vb.alloc;

    if (asz <= sz) {
        std::copy(a.begin(), a.end(), vb.elem);
        for (T* p=vb.elem+asz; p!=vb.space; p++) {
            p->~T();
        }
    }
    else {
        std::copy(a.begin(), a.end()+sz, vb.elem);
        std::uninitialized_copy(a.begin()+sz, a.end(),vb.space);
    }
    vb.space = vb.elem+asz;
    return *this;
}

template<class T, class A>
void vector<T,A>::destroy_elements() {
	for (T* p=vb.elem; p!=vb.last; p++) {
		p->~T();
	}
	vb.space = vb.elem;
}
