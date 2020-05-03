//============================================================================
// Name        : template_convertor.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>

template<typename Target = std::string, typename Source = std::string>
Target to(Source arg)                       // convert Source to Target
{
    std::stringstream interpreter;
    Target result;
    if (       !(interpreter << arg)                    // write arg into stream
            || !(interpreter >> result)                 // read result from stream
            || !(interpreter >> std::ws).eof())         // stuff left in stream?
        throw std::runtime_error{"to<>() failed"};
    return result;
}

int main() {
    auto x1 = to<std::string,double>(1.2);  // very explicit (and verbose)
    auto x2 = to<std::string>(1.2);         // Source is deduced to double
    auto x3 = to<>(1.2);                    // Target is defaulted to string; Source is deduced to double
    auto x4 = to(1.2);                      // the <> is redundant

	return 0;
}
