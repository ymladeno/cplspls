/*
 * Calculator.cpp
 *
 *  Created on: Jan 4, 2020
 *      Author: osboxes
 */

#include "Calculator.hpp"
#include "Error.hpp"
#include <iostream>

//add and subtract
double Calculator::expr(bool get) {

    double left = term(get);

    for(;;) {
        switch (ts.current().kind) {
        case Kind::plus:
            left+=term(true);
            break;
        case Kind::minus:
            left-=term(true);
            break;
        default:
            return left;
        }
    }
    return left;
}

//multiply and divide
double Calculator::term(bool get) {
    double left = prim(get);

    for(;;) {
        switch (ts.current().kind) {
        case Kind::mul:
            left*=prim(true);
            break;
        case Kind::div:
            if (auto d = prim(true))
            {
                left/=d;
                break;
            }
            __ERROR("divide by zero");
        default:
            return left;
        }
    }
    return left;
}

double Calculator::prim(bool get) {
    if (get) {
        ts.get();
    }

    switch(ts.current().kind) {
    case Kind::name:
        if (table.end() != table.find(ts.current().string_val)) {
            double& d = table[ts.current().string_val];
            if (ts.current().kind == Kind::assign) {
                d = expr(true);
            }
            return d;
        }
        __ERROR("Key not found");

    case Kind::number:
    {
        double d = ts.current().number_val;
        ts.get();
        return d;
    }

    case Kind::minus:                       //unary minus
        return -prim(true);

    case Kind::lp:
    {
        auto e = expr(true);
        if (ts.current().kind != Kind::rl) {
            __ERROR("')' expected!");
        }
        ts.get();                           //eat ')'
        return e;
    }

    default:
        __ERROR("primary expected");
    }
}

void Calculator::calculate() {
    for(;;) {
        ts.get();
        switch(ts.current().kind) {
        case Kind::end:
            break;
        case Kind::print:
            continue;
        }
        std::cout << expr(false) << std::endl;
    }
}
