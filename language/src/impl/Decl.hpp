/*
 * Decl.hpp
 *
 *  Created on: May 16, 2020
 *      Author: osboxes
 */

#ifndef IMPL_DECL_HPP_
#define IMPL_DECL_HPP_

namespace impl {

template<typename D>
struct Decl : Stmt<Node<D> > {
    basic_decl_data<D>              decl_data;
    ipr::Named_map*                 pat;
    val_sequence<ipr::Substitution> args;

    Decl() : decl_data(0), pat(0) { }

    const ipr::Sequence<ipr::Substitution>& substitutions()  const { return args; }
    const ipr::Named_map&                   generating_map() const override { return *util::check(pat); }
    const ipr::Linkage&                     lang_linkage()   const override;
    const ipr::Region&                      home_region()    const override;
};

}



#endif /* IMPL_DECL_HPP_ */
