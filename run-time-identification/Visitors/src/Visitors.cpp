//============================================================================
// Name        : Visitors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <utility>
#include <utility>

class Visitor;

class Node {
public:
    virtual void accept(Visitor&) = 0;
    virtual ~Node() {}
};

class Expr;
class Stmt;

class Visitor {
public:
    virtual void accept(Expr&) = 0;
    virtual void accept(Stmt&) = 0;
    virtual ~Visitor() {}
};

class Expr : public Node {
public:
    void accept(Visitor& v) override { v.accept(*this); }
};

class Stmt : public Node {
public:
    void accept(Visitor& v) override { v.accept(*this); }
};

class Do1_visitor : public Visitor {
    void accept(Expr&) { std::cout << "do1 to Expr\n"; }
    void accept(Stmt&) { std::cout << "do1 to Stmt\n"; }
};

class Do2_visitor : public Visitor {
    void accept(Expr&) { std::cout << "do2 to Expr\n"; }
    void accept(Stmt&) { std::cout << "do2 to Stmt\n"; }
};

void test(Visitor& do1, Visitor& do2)
{
    Expr e{};
    Stmt s{};
    std::vector<std::pair<Node*, Visitor*>> vn {{&e,&do1}, {&s,&do1}, {&e,&do2}, {&s,&do2}};

    for (auto p : vn)
        p.first->accept(*p.second);
}

int main() {
    Do1_visitor do1{};
    Do2_visitor do2{};
    test(do1, do2);
	return 0;
}
