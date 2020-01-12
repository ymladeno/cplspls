/*
 * Calculator.hpp
 *
 *  Created on: Jan 4, 2020
 *      Author: osboxes
 */

#ifndef CALCULATOR_HPP_
#define CALCULATOR_HPP_

#include "CTokens.hpp"
#include <string>
#include <map>

class Calculator {
public:
    double expr(bool get);
    double term(bool get);
    double prim(bool get);

private:
    CTokens ts;
    std::map<std::string, double> table;
};

#endif /* CALCULATOR_HPP_ */
