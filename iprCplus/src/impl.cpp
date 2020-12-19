/*
 * impl.cpp
 *
 *  Created on: Dec 11, 2020
 *      Author: osboxes
 */


#include "../include/ipr/impl.hpp"

namespace ipr {
namespace impl {

// ------------
// Impl Lexicon
// ------------
Lexicon::Lexicon() {}

Lexicon::~Lexicon() {}

const ipr::Type& Lexicon::void_type()   const { return voidtype;   };
const ipr::Type& Lexicon::bool_type()   const { return booltype;   };
const ipr::Type& Lexicon::char_type()   const { return chartype;   };
const ipr::Type& Lexicon::int_type()    const { return inttype;    };
const ipr::Type& Lexicon::long_type()   const { return longtype;   };
const ipr::Type& Lexicon::double_type() const { return doubletype; };

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
const ipr::Type& Scope::type() const { return decls; }

impl::Identifier* expr_factory::make_identifier(const String& s) {
    return
}
} //namespace impl
} //namespace ipr
