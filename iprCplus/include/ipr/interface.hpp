/*
 * interface.hpp
 *
 *  Created on: Dec 6, 2020
 *      Author: osboxes
 */

#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

#include <cstdint>

namespace ipr {

struct Visitor;     //base class for all IPR Visitor classes
struct Type;        //general types
// struct Stmt;        //general statement
struct Name;        //general names
// struct Region;      //general region
// struct Annotation;  //
struct Expr;        //general expression
struct Node;
struct As_type;
struct Linkage;
struct String;

enum class Category_code {
    Unknown,
    Annotation,
    Region,
    Comment,
    String,
    Linkage,
    Array,
    Class,
    Decltype,
    Enum,
    Function,
    Namespace,
    Var,
    As_type,
    Scope,
    Product,
    Identifier,
    Qualified,
    Last_code,
};

// enum class Line_number : uint32_t{};
// enum class Column_number : uint32_t{};

// struct Basic_location {
//     Line_number line = {};
//     Column_number column = {};
// };

// enum class Unit_index : uint32_t {};

// struct Unit_location : Basic_location {
//     Unit_index unit = {};       //ID of the unit
// };

// enum class File_index : uint32_t {};

// struct Source_location : Basic_location {
//     File_index file = {};       //ID of the file
// };

template<Category_code Cat, typename T = Expr>
struct Category : T {
protected:
    Category() : T(Cat) { }
};

//Node is a base class. A hook for Visitor pattern
struct Node {
    const Category_code category;
    // hook for visitor classes
    virtual void accept(Visitor&) const = 0;
protected:
    constexpr Node(Category_code c) : category{c} {}
};

struct String : Category<Category_code::String, Node> {};

// struct Region : Category<Category_code::Region, Node> {

// };

//Expr is a sequence of operators and operands that specifies a computation
//Every expr has a type
struct Expr : Node {
    // virtual const Type& type() const = 0;
protected:
    constexpr Expr(Category_code c) : Node(c) { }
};

struct Type : Expr {
    //All types has a name
    // virtual const Name& name() const = 0;
protected:
    constexpr Type(Category_code c) : Expr(c) {}
};

template<class Cat, class Operand = const Expr&>
struct Unary : Cat {
    using Arg_type = Operand;
    // virtual Operand operand() const = 0;
};

// struct Product : Unary<Category<Category_code::Product, Type>, const Sequence<Type>&>{};

// struct Identifier : Unary<Category<Category_code::Identifier, Name>, const String&>{};

// //Stmt is an Expr
// struct Stmt : Expr {
//     virtual const Unit_location&        unit_location()   const = 0; // line in file
//     virtual const Source_location&      source_location() const = 0; // file
//     virtual const Sequence<Annotation>& annotation()      const = 0;

//     virtual ~Stmt() {}

// protected:
//     Stmt(Category_code c) : Expr(c) { }
// };

// //Decl is a Stmt that introduces a name
// struct Decl : Stmt {
//     enum Specifier { /* storage class, virtual, access control, etc. */ };
//     virtual Specifier specifiers() const = 0;

//     virtual const Linkage& lang_linkage()    const = 0;
//     virtual const Name&    name()            const = 0;
//     virtual const Region&  home_region()     const = 0;
//     virtual const Region&  lexical_region()  const = 0;
//     virtual bool           has_initializer() const = 0;
//     virtual const Expr&    initializer()     const = 0;
//     // ...

// protected:
//     Decl(Category_code c) : Stmt(c) { }
// };

// struct Var : Category<var, Decl> {

// };

// struct Scope : Category<scope> {

// };

struct Lexicon {
    virtual const Type& int_type() const = 0;
};

// template<typename T>
// struct Udt : Type {
// protected:
//     Udt(Category_code c) : Type(c) {}
// };

// struct Namespace : Category<namespace, Udt<Decl>> {

// };

// struct Global_scope : Namespace {};

struct Visitor {
    virtual void visit(const Node&) = 0;
};

// struct Translation_unit {
//     struct Visitor;
//     virtual const ipr::Global_scope& global_namespace() const = 0;
// };

struct Name : Node {
protected:
    constexpr Name(Category_code c) : Node(c) {}
};

template<class Cat, class First = const Expr&, class Second = const Expr&>
struct Binary : Cat {
    using Arg1_type = First;
    using Arg2_type = Second;
    // virtual First first() const = 0;
    // virtual Second second() const = 0;
};

// struct Qualified : Binary<Category<Category_code::Qualified, Type>,
//                             ipr::Type_qualifier, const Type&> {

// };

struct Linkage : Unary<Category<Category_code::Linkage, Node>, const String&> {
    // Arg_type language() const { return operand(); }
};

struct As_type : Binary<Category<Category_code::As_type, Type>,
                        const Expr&, const Linkage& > {
    // Arg1_type expr() const { return first(); }
    // Arg2_type lang_linkage() const { return second(); }
};

}

#endif /* INTERFACE_HPP_ */
