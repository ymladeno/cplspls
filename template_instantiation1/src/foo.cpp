/*
 * foo.cpp
 *
 *  Created on: Oct 4, 2020
 *      Author: osboxes
 */

#include "foo.hpp"
#include "MyVector.hpp"

template class MyVector<int>;

void foo(MyVector<int>& v)
{
    v[0] = 100;
}
