/*
 * Decl.hpp
 *
 *  Created on: May 15, 2020
 *      Author: osboxes
 */

#ifndef IPR_DECL_HPP_
#define IPR_DECL_HPP_

#include "Stmt.hpp"

namespace ipr {

struct Decl : Stmt {
    enum Specifier { /* storage class, virtual, access control, etc. */ };
    virtual Specifier specifiers() const = 0;

    virtual const Linkage& lang_linkage()    const = 0;
    virtual const Name&    name()            const = 0;
    virtual const Region&  home_region()     const = 0;
    virtual const Region&  lexical_region()  const = 0;
    virtual bool           has_initializer() const = 0;
    virtual const Expr&    initializer()     const = 0;
    // ...

protected:
    Decl(Category_code c) : Stmt(c) { }
};

}



#endif /* IPR_DECL_HPP_ */
