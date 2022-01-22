/*
 * select.cpp
 *
 *  Created on: Dec 27, 2020
 *      Author: osboxes
 */

template<unsigned N, typename... Cases>             // general case; never instantiated
struct nselect;

template<unsigned N, typename T, typename... Cases>
struct nselect<N,T,Cases...> : nselect<N-1, Cases...> {
};

template<typename T, typename ... Cases>            // final case: N==0
struct nselect<0,T,Cases...> {
    using type = T;
};

template<unsigned N, typename... Cases>
using Select = typename nselect<N,Cases...>::type;
