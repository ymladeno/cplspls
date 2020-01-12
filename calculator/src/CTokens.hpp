/*
 * CToken.hpp
 *
 *  Created on: Jan 4, 2020
 *      Author: osboxes
 */

#ifndef CTOKENS_HPP_
#define CTOKENS_HPP_

#include <string>
#include <istream>

enum class Kind : char {name, number, end, plus='+', minus='-', mul='*', div='/', print=';', assign='=', lp='(', rl='('};

struct CSimpleToken {
    Kind kind;
    std::string string_val;
    double number_val;
};

class CTokens {
public:
    CTokens(std::istream& is) : is{is} {}
    CSimpleToken get();                         //next
    const CSimpleToken& current();              //most recently read

private:
    std::istream& is;
    CSimpleToken ct {Kind::end};
};

#endif /* CTOKENS_HPP_ */
