/*
 * main.cpp
 *
 *  Created on: Mar 15, 2020
 *      Author: osboxes
 */

#include <iostream>
#include "Date.hpp"

int main() {
    Chronos::Date d1{10, Chronos::Month::jan, 1915};
    Chronos::Date d2 = d1;

    if (Chronos::diff(d1, d2)) {
        std::cout << "d1 and d2 are the same date\n";
    }

    return 0;
}
