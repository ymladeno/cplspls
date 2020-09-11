/*
 * Stmt.hpp
 *
 *  Created on: May 16, 2020
 *      Author: osboxes
 */

#ifndef IMPL_STMT_HPP_
#define IMPL_STMT_HPP_


namespace impl {

template<typename S>
struct impl::Stmt : S {
    // logical position in translation unit
    ipr::Unit_location unit_locus;

    // source file, line, and column
    ipr::Source_location src_locus;
    ref_sequence<ipr::Annotation> notes;
    const ipr::Unit_location&             unit_location()   const override { return unit_locus; }
    const ipr::Source_location&           source_location() const override { return src_locus; }
    const ipr::Sequence<ipr::Annotation>& annotation()      const override { return notes; }
};

}



#endif /* IMPL_STMT_HPP_ */
