/*
 * vector_base.cpp
 *
 *  Created on: May 12, 2019
 *      Author: osboxes
 */

#include "vector_base.hpp"

template<class T, class A>
vector_base<T,A>::vector_base(vector_base&& a) :
alloc{a.alloc},
elem {a.elem },
space{a.space},
last {a.last } {
	a.elem = a.space = a.last = nullptr;	//no longer owns any memory
}

template<class T, class A>
vector_base<T,A>& vector_base<T,A>::operator=(vector_base&& a) {
	swap(*this,a);
	return *this;
}
