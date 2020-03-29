/*
 * vector_base.hpp
 *
 *  Created on: May 12, 2019
 *      Author: osboxes
 */

#ifndef SRC_VECTOR_BASE_HPP_
#define SRC_VECTOR_BASE_HPP_

#include <iostream>

// elem     space          last
//  |         |             |
// ------------------------------
//  elements | extra space | last
// ------------------------------
// <- size ->
// <-       capacity     ->

template<class T>
class allocator;

template<class T, class A=allocator<T>>
struct vector_base {
	A  alloc;
	T* elem;
	T* space;
	T* last;

	vector_base(const A& a, size_t n) :
		alloc{a},
		elem {alloc.allocate(n)},
		space{elem + n},
		last {elem + n} {}

	virtual ~vector_base() { alloc.deallocate(); };

	vector_base(const vector_base&) = delete;				//no copy operations
	vector_base& operator=(const vector_base&) = delete;

	vector_base(vector_base&&);								//move operations
	vector_base& operator=(vector_base&&);
};

#include "vector_base.ipp"

#endif /* SRC_VECTOR_BASE_HPP_ */
