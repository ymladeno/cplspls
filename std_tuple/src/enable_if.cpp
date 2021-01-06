/*
 * enable_if.cpp
 *
 *  Created on: Jan 6, 2021
 *      Author: osboxes
 */

///////////////////////////////
// enable_if implementation
//////////////////////////////
template<bool B, typename T = void>
struct enable_if {
    typedef T type;
};

template<typename T>
struct enable_if<false , T> {};             // no ::type if B==false

template<bool B, typename T = void>
using Enable_if = typename enable_if<B,T>::type;
