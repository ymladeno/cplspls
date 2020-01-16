//============================================================================
// Name        : calculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CTokens.hpp"
#include "Calculator.hpp"
#include "Error.hpp"

int main() {
    try {
        Calculator c1;

        c1.addConstant("pi", 3.1415926535897932385);
        c1.addConstant("e", 2.7182818284590452354);

        c1.calculate();
    } catch (const Error& e) {
        std::cout << e.dump() << std::endl;
        return 1;
    } catch (...) {
        std::cout << "Unknown exception\n";
        return 1;
    }

	return 0;
}
