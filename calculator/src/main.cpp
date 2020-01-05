//============================================================================
// Name        : calculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CTokens.hpp"

static void expr();
static void term();
static void primary();

//add and subtract
static void expr(bool get) {

    double left = term(get);

    for(;;) {
        switch (ts.current().m_kind) {
        case Kind::plus:
            break;
        case Kind::minus:
            break;
        default:
            term();
        }
    }
}

//multiply and divide
static void term(bool get) {

}

static void primary() {

}

int main() {

	return 0;
}
