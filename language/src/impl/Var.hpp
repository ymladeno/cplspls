/*
 * Var.hpp
 *
 *  Created on: May 16, 2020
 *      Author: osboxes
 */

#ifndef IMPL_VAR_HPP_
#define IMPL_VAR_HPP_

#include "ipr/Expr.hpp"
#include "ipr/Region.hpp"
#include "ipr/Var.hpp"

namespace impl {

struct Var : impl::Decl<ipr::Var> {
    const ipr::Expr* init;
    const ipr::Region* lexreg;
    Var();
    bool has_initializer() const override;
    const ipr::Expr& initializer() const override;
    const ipr::Region& lexical_region() const override;
};

}



#endif /* IMPL_VAR_HPP_ */
