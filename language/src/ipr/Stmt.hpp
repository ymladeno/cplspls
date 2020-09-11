/*
 * Stmt.hpp
 *
 *  Created on: May 15, 2020
 *      Author: osboxes
 */

#ifndef IPR_STMT_HPP_
#define IPR_STMT_HPP_

#include "Expr.hpp"

namespace ipr {

struct Stmt : Expr {
    virtual const Unit_location&        unit_location()   const = 0; // line in file
    virtual const Source_location&      source_location() const = 0; // file
    virtual const Sequence<Annotation>& annotation()      const = 0;

    virtual ~Stmt() {}

protected:
    Stmt(Category_code c) : Expr(c) { }
};

}

#endif /* IPR_STMT_HPP_ */
