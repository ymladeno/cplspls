/*
 * CToken.cpp
 *
 *  Created on: Jan 4, 2020
 *      Author: osboxes
 */

#include "CTokens.hpp"

CSimpleToken CTokens::get() {
    return CSimpleToken{};
}

const CSimpleToken& CTokens::current() {
    return CSimpleToken{};
}
