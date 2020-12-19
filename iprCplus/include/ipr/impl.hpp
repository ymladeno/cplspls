/*
 * impl.hpp
 *
 *  Created on: Dec 6, 2020
 *      Author: osboxes
 */

#ifndef IMPL_HPP_
#define IMPL_HPP_

#include "interface.hpp"
#include "utility.hpp"

namespace ipr {
namespace impl {

// make the template argument type available to users
template<typename T>
struct Node : T {
    using Interface = T;
    void accept(ipr::Visitor& v) const final { v.visit(*this); }
};

template<typename Interface>
struct Expr : impl::Node<Interface> {

    // constraint is the type of the expression
    const ipr::Type* constraint;
    Expr() : constraint(0) { }

    const ipr::Type& type() const override {
        return *util::check(constraint);
    }
};

template<class T>
struct Type : impl::Expr<T> {

};

//Helper class
template<typename Interface>
struct Unary : Interface {

};

template<typename T>
using Unary_node = Unary<Node<T>>;

template<class Interface>
struct Binary : Interface {
    using typename Interface::Arg1_type;
    using typename Interface::Arg2_type;

    struct Rep {
        Arg1_type first;
        Arg2_type second;
    };
    Rep rep;
    Arg1_type first() const final { return rep.first; }
    Arg2_type second() const final { return rep.second; }
};

template<class T>
struct Builtin : impl::Expr<T> {

};

struct Stmt_common {
    ipr::Unit_location unit_locus;        // logical position in translation unit
    ipr::Source_location src_locus;       // source file, line, and column
};

template<class S>
struct Stmt : S, Stmt_common {

    const ipr::Unit_location&             unit_location()   const override { return unit_locus; }
    const ipr::Source_location&           source_location() const override { return src_locus; }
};

template<class> struct master_decl_data;

template<class Interface>
struct basic_decl_data {
    master_decl_data<Interface>* master_data;

    explicit basic_decl_data(master_decl_data<Interface>* mdd) : master_data(mdd) {}
};

template<class Interface>
struct master_decl_data : basic_decl_data<Interface> {
    //Declaration which is consider to be definition
    const Interface* def;
    const ipr::Linkage* langLinkage;
    const ipr::Region* home;
};

template<typename D>
struct Decl : Stmt<Node<D> > {
    basic_decl_data<D>              decl_data;

    Decl() : decl_data(0) { }

    const ipr::Linkage& lang_linkage() const final {
        return util::check(util::check(decl_data)->langlinkage);
    }
    const ipr::Region&  home_region()  const override {
        return util::check((util::check(decl_data)->home));
    }
};

struct Var : impl::Decl<ipr::Var> {
    const ipr::Expr*   init;
    const ipr::Region* lexreg;
    Var();
    bool               has_initializer() const override;
    const ipr::Expr&   initializer()     const override;
    const ipr::Region& lexical_region()  const override;
};

template<typename Seq>
struct typed_sequence : impl::Type<ipr::Product>{
    Seq seq;
};

struct decl_sequence {

};

struct Scope : impl::Node<ipr::Scope> {
    const ipr::Type& type() const;
private:
    typed_sequence<decl_sequence> decls;
};

struct Lexicon : ipr::Lexicon {
    Lexicon();
    ~Lexicon();

    const ipr::Type& void_type()   const final;
    const ipr::Type& bool_type()   const final;
    const ipr::Type& char_type()   const final;
    const ipr::Type& int_type()    const final;
    const ipr::Type& long_type()   const final;
    const ipr::Type& double_type() const final;

    //const ipr::Linkage& cxx_linkage() const final;
    //const ipr::Linkage& c_linkage() const final;

private:
    const impl::Builtin<ipr::As_type> voidtype;
    const impl::Builtin<ipr::As_type> booltype;
    const impl::Builtin<ipr::As_type> chartype;
    const impl::Builtin<ipr::As_type> inttype;
    const impl::Builtin<ipr::As_type> longtype;
    const impl::Builtin<ipr::As_type> doubletype;
};

template<typename T>
struct Buildin : impl::Expr<T> {

};

struct Region : impl::Node<ipr::Node> {
    impl::Scope scope;
};

template<typename Interface>
struct Udt : impl::Type<Interface> {
    Region body;
};

template<typename T>
struct unit_base : T {
    unit_base(impl::Lexicon& l)
    : context{l} {

    }
    Scope* global_scope(){ return &global_ns.body.scope; }

private:
    impl::Udt<ipr::Global_scope> global_ns;
    impl::Lexicon& context;
};

using Translation_unit = unit_base<ipr::Translation_unit>;
using Identifier       = Unary_node<ipr::Identifier>;

struct expr_factory {
    Identifier* make_identifier(const ipr::String&);
    Identifier* make_identifier(const char*);
    Identifier* make_identifier(const std::string&);
private:
    util::rb_tree::container<impl::Identifier> ids;
};

}
}

#endif /* IMPL_HPP_ */
