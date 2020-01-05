/*
 * CToken.hpp
 *
 *  Created on: Jan 4, 2020
 *      Author: osboxes
 */

#ifndef CTOKENS_HPP_
#define CTOKENS_HPP_

#include <string>

enum class Kind : char {name, number, end, plus='+', minus='-', mul='*', div='/', print=';', assign='=', lp='(', rl='('};

struct CSimpleToken {
    Kind m_kind;
    std::string string_val;
    double d_val;
};

class CTokens {
public:
    CSimpleToken get();             //next
    const CSimpleToken& current();   //most recently read
};

#endif /* CTOKENS_HPP_ */
