/*
 * Ifstatement.hpp
 *
 *  Created on: Apr 5, 2020
 *      Author: osboxes
 */

#ifndef IFSTATEMENT_HPP_
#define IFSTATEMENT_HPP_

#include "Node.hpp"

class If_statement: public Node {
public:
    If_statement();
    virtual ~If_statement();
    Type type() override final;
};

#endif /* IFSTATEMENT_HPP_ */
