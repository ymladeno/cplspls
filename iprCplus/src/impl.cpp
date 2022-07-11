/*
 * impl.cpp
 *
 *  Created on: Dec 11, 2020
 *      Author: osboxes
 */


#include "ipr/impl.hpp"

namespace ipr {
namespace impl {

// ------------
// Impl Lexicon
// ------------
Lexicon::Lexicon() : inttype{} {}
Lexicon::~Lexicon() {}

const ipr::Type& Lexicon::int_type() const { return inttype; };

//const ipr::Linkage& Lexicon::cxx_linkage() const {
//    return const_cast<Lexicon*>(this)->get_linkage("C++")};
//}
//
//const ipr::Linkage& Lexicon::c_linkage() const {
//    return const_cast<Lexicon*>(this)->get_linkage("C")};
//};

// ------------
// Impl Scope
// ------------
// const ipr::Type& Scope::type() const { return decls; }

// impl::Identifier* expr_factory::make_identifier(const String& s) {
//     return
// }
} //namespace impl
} //namespace ipr
