/*
 * Calculator.cpp
 *
 *  Created on: Jan 4, 2020
 *      Author: osboxes
 */

#include "Calculator.hpp"
#include "error.hpp"
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
            return -1;                      //error("divide by zero")
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
            return d;
        }
        return error("Key not found");

    case Kind::number:
    {
        double d = ts.get().number_val;
        return d;
    }

    case Kind::minus:                       //unary minus
        return -prim(true);

    case Kind::lp:
    {
        auto e = expr(true);
        if (ts.current().kind != Kind::rl) {
            return error("')' expected!");
        }
        ts.get();                           //eat ')'
        return e;
    }

    default:
        return error("primary expected");
    }
}

