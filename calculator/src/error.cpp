/*
 * CError.cpp
 *
 *  Created on: Jan 11, 2020
 *      Author: osboxes
 */

#include <iostream>
#include "error.hpp"

int error(const std::string& what) {
    std::cout << what << std::endl;
    return -1;
}

