/*
 * CToken.hpp
 *
 *  Created on: Jan 4, 2020
 *      Author: osboxes
 */

#ifndef CTOKENS_HPP_
#define CTOKENS_HPP_

#include "CSimpleToken.hpp"
#include <string>
#include <istream>

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
