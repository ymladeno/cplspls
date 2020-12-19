//============================================================================
// Name        : language.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "../include/ipr/impl.hpp"

int main() {
    ipr::impl::Lexicon lexicon { };
    ipr::impl::Translation_unit unit { lexicon };   // current translation unit

    ipr::impl::Scope* global_scope = unit.global_scope();

    // Build the variable's name,
    const ipr::Name* name = lexicon.make_identifier("bufsz");

    // then its type,
    auto& type = lexicon.get_qualified(Type_qualifier::Const, lexicon.int_type());
    // and the actual impl::Var node,
    ipr::impl::Var* var = global_scope->make_var(*name, type);

	return 0;
}
