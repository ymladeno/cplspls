/*
 * Error.hpp
 *
 *  Created on: Jan 14, 2020
 *      Author: osboxes
 */

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>
#include <stdexcept>
#include <iostream>

#define __ERROR(what) throw Error(__func__, __LINE__, what)

struct Error {
    Error(const std::string& func, const int line, const std::string& what) :
        func {func},
        line {line},
        text {what} {}

        std::string dump() const {
            return std::string {func + ": " + std::to_string(line) + ": " + text};
        }

private:
    std::string func;
    int         line;
    std::string text;
};

#endif /* ERROR_HPP_ */
