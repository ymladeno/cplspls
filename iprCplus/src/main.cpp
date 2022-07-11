//============================================================================
// Name        : language.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "ipr/impl.hpp"

int main() {
    ipr::impl::Lexicon lexicon{};
    // ipr::impl::Module m{lexicon};
    // ipr::impl::Translation_unit unit{lexicon, m};   // current translation unit
    // ipr::impl::Scope* global_scope = unit.global_scope();

    // // Build the variable's name,
    // const ipr::Name* name = lexicon.make_identifier("bufsz");

    // // then its type,
    // auto& type = lexicon.get_qualified(Type_qualifier::Const, lexicon.int_type());

    // // and the actual impl::Var node,
    // ipr::impl::Var* var = global_scope->make_var(*name, type);
    // var->init = lexicon.make_literal(lexicon.init_type(), "1024");
	return 0;
}
