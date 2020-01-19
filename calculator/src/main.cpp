//============================================================================
// Name        : calculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "CTokens.hpp"
#include "Calculator.hpp"
#include "Error.hpp"
#include <iostream>
#include <sstream>
#include <string>

//to check about function return
std::string arguments(int argc, char** argv) {

    std::string l_res_str {};
    for (auto i=1; i<argc; i++) {
        l_res_str += argv[i];
    }
    return l_res_str;
}

int main(int argc, char** argv) {
    try {
        CTokens ts {std::cin};
        Calculator c1 {ts};

        c1.addConstant("pi", 3.1415926535897932385);
        c1.addConstant("e", 2.7182818284590452354);

        if (argc > 1) {
            auto string_arguments = arguments(argc, argv);
            std::istringstream s_arg {string_arguments};
            ts.set_input(s_arg);
        }

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
