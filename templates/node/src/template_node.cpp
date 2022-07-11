//============================================================================
// Name        : template_node.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Balance tree
//               More info : binary tree framework [Austern,2003]
//============================================================================

// Can't be compiled

#include <iostream>
#include <vector>

struct Red_black_balance {
    template<typename N>
    bool compare(const N& n1, const N& n2) {
        return n1.v<n2.v;
    }
};

template<typename N>
struct Node_base : N::balance_type {
    N* left_child;
    N* right_child;

    Node_base() : left_child{}, right_child{} {
        //std::cout << "Node_base()\n";
    }

    void insert(N* n) {

        if (!left_child)
            add_left(n);
        else {
            if (this->compare(*n, *left_child)) {
                add_left(n);
            }
            else {
                add_right(n);
            }
        }
    }

private:
    void add_left(N* p)
    {
        if (left_child == nullptr)
            left_child = p;
        else
            left_child->add_left(p);
    }

    void add_right(N* p)
    {
        if (right_child == nullptr)
            right_child = p;
        else
            right_child->add_right(p);
    }
};

template<typename Val, typename Balance>
struct Node : public Node_base<Node<Val, Balance>> {
    // using balance_type = Balance;

    Node(Val v=0) : v{v} {
        //std::cout << "Node(Val v=0)\n";
    }
    Val v;
};

template<typename T>
using Rbnode = Node<T, Red_black_balance>;

void user(const std::vector<double>& v)
{
    Rbnode<double> root{};
    for (auto x : v) {
        root.insert(new Rbnode<double>{x});
    }
}

int main() {
    std::vector<double> d{-3.457, 7.98, 10.3, 0.989};
    user(d);
	return 0;
}
