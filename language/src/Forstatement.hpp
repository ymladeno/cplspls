/*
 * Forstatement.hpp
 *
 *  Created on: Apr 5, 2020
 *      Author: osboxes
 */

#ifndef FORSTATEMENT_HPP_
#define FORSTATEMENT_HPP_

#include "Node.hpp"

class For_statement: public Node {
public:
    For_statement();
    virtual ~For_statement();
    Type type() override final;
};

#endif /* FORSTATEMENT_HPP_ */
