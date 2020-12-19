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
struct Stmt;        //general statement
struct Linkage;     //general language linkage
struct Name;        //general names
struct Region;      //general region
struct Annotation;  //
struct Expr;        //general expression

enum Category_code {
    unknown_cat,
    annotation_cat,
    region_cat,
    comment_cat,
    string_cat,
    linkage_cat,
    array_cat,
    class_cat,
    decltype_cat,
    enum_cat,
    function_cat,
    namespace_cat,
    var_cat,
    as_type_cat,
    scope_cat,
    product_cat,
    identifier_cat,
    last_code_cat
};

enum class Line_number : uint32_t{};
enum class Column_number : uint32_t{};

struct Basic_location {
    Line_number line = {};
    Column_number column = {};
};

enum class Unit_index : uint32_t {};

struct Unit_location : Basic_location {
    Unit_index unit = {};       //ID of the unit
};

enum class File_index : uint32_t {};

struct Source_location : Basic_location {
    File_index file = {};       //ID of the file
};

template<typename T>
struct Sequence {

};

struct Annotation {

};

template<Category_code Cat, typename T = Expr>
struct Category : T {
protected:
    Category() : T(Cat) { }
};

//Node is a base class. A hook for Visitor pattern
struct Node {
    const int node_id;
    const Category_code category;

    // hook for visitor classes
    virtual void accept(Visitor&) const = 0;

protected:
    Node(Category_code);
};

struct String : Category<string_cat, Node> {

};

struct Region : Category<region_cat, Node> {

};

//Expr is a sequence of operators and operands that specifies a computation
//Every expr has a type
struct Expr : Node {
    virtual const Type& type() const = 0;

protected:
    Expr(Category_code c) : Node(c) { }
};

struct Type : Expr {
    //All types has a name
    //virtual const Name& name() const = 0;

protected:
    Type(Category_code c) : Expr(c) {}
};

//there are two operands - first and second
template<class Cat, class First = const Expr&, class Second = const Expr&>
struct Binary : Cat {
    using Arg1_type = First;
    using Arg2_type = Second;
    //virtual First first() = 0;
    //virtual Second second() = 0;
};

//ex. sizeof (T)
template<class Cat, class Operand = const Expr&>
struct Unary : Cat {

};

struct As_type : Binary<Category<as_type_cat, Type>,
                        const Expr&, const Linkage&> {

};

//C and C++ linkage
struct Linkage : Unary<Category<linkage_cat, Node>, const String&> {

};

struct Product : Unary<Category<product_cat, Type>, const Sequence<Type>&>{};

struct Identifier : Unary<Category<identifier_cat, Name>, const String&>{};

//Stmt is an Expr
struct Stmt : Expr {
    virtual const Unit_location&        unit_location()   const = 0; // line in file
    virtual const Source_location&      source_location() const = 0; // file
    virtual const Sequence<Annotation>& annotation()      const = 0;

    virtual ~Stmt() {}

protected:
    Stmt(Category_code c) : Expr(c) { }
};

//Decl is a Stmt that introduces a name
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

struct Var : Category<var_cat, Decl> {

};

struct Scope : Category<scope_cat> {

};

struct Lexicon {
    virtual const Type& void_type()   const = 0;
    virtual const Type& bool_type()   const = 0;
    virtual const Type& char_type()   const = 0;
    virtual const Type& int_type()    const = 0;
    virtual const Type& long_type()   const = 0;
    virtual const Type& double_type() const = 0;

    //virtual const Linkage& cxx_linkage() const = 0;
    //virtual const Linkage& c_linkage() const = 0;
};

template<typename T>
struct Udt : Type {
protected:
    Udt(Category_code c) : Type(c) {}
};

struct Namespace : Category<namespace_cat, Udt<Decl>> {

};

struct Global_scope : Namespace {};

struct Visitor {
    virtual void visit(const Node&) = 0;
};

struct Translation_unit {

};

struct Name : Node {

protected:
    Name(Category_code c) : Node(c) {}
};

}

#endif /* INTERFACE_HPP_ */
