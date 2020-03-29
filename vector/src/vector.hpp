/*
 * vector.hpp
 *
 *  Created on: May 12, 2019
 *      Author: osboxes
 */

#ifndef SRC_VECTOR_HPP_
#define SRC_VECTOR_HPP_

#include "vector_base.hpp"

template<class T, class A=allocator<T>>
class vector {
private:
    vector_base<T,A> vb;
    void destroy_elements();

public:
    explicit vector(size_t n, const T& val=T(), const A& = A());
    virtual ~vector()       { destroy_elements(); };
    vector& operator=(const vector&);
    size_t size()     const { return vb.space - vb.elem; }
    size_t capacity() const { return vb.last - vb.elem;  }
};

#include "vector.ipp"

#endif /* SRC_VECTOR_HPP_ */
