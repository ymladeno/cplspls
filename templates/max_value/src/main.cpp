/*
 * main.cpp
 *
 *  Created on: Jan 13, 2022
 *      Author: osboxes
 */

#include <limits.h>
#include <iostream>

template<typename T> T max_value();
template<> constexpr int max_value() { return INT_MAX; }
template<> constexpr char max_value() { return CHAR_MAX; }

template<typename Iter>
void my_algo() {
    auto x = max_value<Iter>();
    std::cout << ":" << x << "\n";
}

int main() {
    my_algo<int>();
    my_algo<char>();
}
