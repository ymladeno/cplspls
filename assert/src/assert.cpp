//============================================================================
// Name        : assert.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cstdio>

namespace Assert {
    enum class e_mode {throw_, ignore_, terminate_};
    constexpr e_mode current_mode = e_mode::throw_;
    constexpr int current_level = 2;
    constexpr int default_level = 1;

    struct Error : std::runtime_error {
        Error(const std::string& s) : std::runtime_error(s) {}
    };

    std::string compose(const char* p_file, const int p_line, const std::string& p_message) {
        std::ostringstream os {};
        os << p_file << ": " << p_line << " " << p_message << std::endl;
        return os.str();
    }

    constexpr bool level(int n) {
        return (n<=current_level);
    }

    template<bool condition=level(default_level), class Except = Error>
    void dynamic(bool p_assertion, const std::string& p_message = "Assert::dynamic failed") {

        if (p_assertion) {
            return;
        }
        if (current_mode == Assert::e_mode::throw_) {
            throw Error{p_message};
        }
        if (current_mode == Assert::e_mode::terminate_) {
            std::terminate();
        }
    }

    //do nothing
    template<>
    void dynamic<false, Error>(bool, const std::string&) {

    }

    //default action
    void dynamic(bool b, const std::string& s) {
        dynamic<true, Error>(b, s);
    }

    //default message
    void dynamic(bool b) {
        dynamic<true, Error>(b);
    }
}

void f(int n) {
    Assert::dynamic<Assert::level(1), Assert::Error>(
            (n>0 && n<=100), Assert::compose(__func__, __LINE__, "range problem"));
}

int main()
{
    f(101);
}
