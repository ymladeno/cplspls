/*
 * Expr.hpp
 *
 *  Created on: Apr 5, 2020
 *      Author: osboxes
 */

#ifndef EXPR_HPP_
#define EXPR_HPP_

#include "Node.hpp"

namespace ipr {

struct Expr : Node {
    virtual const Type& type() const = 0;

protected:
    Expr(Category_code c) : Node(c) { }
};

}


#endif /* EXPR_HPP_ */
