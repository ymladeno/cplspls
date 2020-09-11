/*
 * Expr.hpp
 *
 *  Created on: May 16, 2020
 *      Author: osboxes
 */

#ifndef IMPL_EXPR_HPP_
#define IMPL_EXPR_HPP_

namespace impl {

template<typename Interface>
struct Expr : impl::Node<Interface> {
    // constraint is the type of the expression
    const ipr::Type* constraint;
    Expr() : constraint(0) { }
    const ipr::Type& type() const override { return *util::check(constraint); }
};

}

#endif /* IMPL_EXPR_HPP_ */
