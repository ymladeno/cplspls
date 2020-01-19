/*
 * CToken.cpp
 *
 *  Created on: Jan 4, 2020
 *      Author: osboxes
 */

#include "CTokens.hpp"
#include "Error.hpp"
#include <cctype>

CSimpleToken CTokens::get() {
    char ch;
    do {
        if (!is->get(ch)) {
            return ct = {Kind::end};
        }
    } while(ch != '\n' && isspace(ch));

    switch (ch) {
        case 0:
            return ct = {Kind::end};

        case ';' :
        case '\n':
            return ct = {Kind::print};

        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '=':
            return ct = {static_cast<Kind>(ch)};

        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        case '.':
            is->putback(ch);
            *is >> ct.number_val;
            ct.kind = Kind::number;
            return ct;

        default:
            if (std::isalpha(ch)) {
                ct.string_val = ch;
                while(is->get(ch) && std::isalnum(ch)) {
                    ct.string_val += ch;
                }
                is->putback(ch);
                ct.kind = Kind::name;
                return ct;
            }
    }

    __ERROR("bad token");
}

const CSimpleToken& CTokens::current() {
    return ct;
}
