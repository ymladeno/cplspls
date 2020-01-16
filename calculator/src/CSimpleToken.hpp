/*
 * CSimpleToken.hpp
 *
 *  Created on: Jan 13, 2020
 *      Author: osboxes
 */

#ifndef CSIMPLETOKEN_HPP_
#define CSIMPLETOKEN_HPP_

#include "Kind.hpp"
#include <string>

struct CSimpleToken {
    Kind kind;
    std::string string_val;
    double number_val;
};

#endif /* CSIMPLETOKEN_HPP_ */
