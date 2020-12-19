/*
 * Cond.hpp
 *
 *  Created on: Apr 5, 2020
 *      Author: osboxes
 */

#ifndef COND_HPP_
#define COND_HPP_

#include "Expr.hpp"

class Cond: public Expr {
public:
    Cond();
    virtual ~Cond();
    virtual Cond* new_expr() override;
    virtual Cond* clone()    override;
};

#endif /* COND_HPP_ */
