//============================================================================
// Name        : template_node.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Balance tree
//============================================================================

#include <iostream>
#include <vector>

template<typename N>
struct Node_base { // doesn’t know about Val (the user data)
    N* left_child;
    N* right_child;

    Node_base() : left_child{}, right_child{} {
        //std::cout << "Node_base()\n";
    }
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

template<typename Val>
struct Node : Node_base<Node<Val>> {
    Val v;
    Node(Val v=0) : v{v} {
        //std::cout << "Node(Val v=0)\n";
    }
};

using My_node = Node<double>;

void user(const std::vector<double>& v)
{
    My_node root{};
    int i = 0;
    for (auto x : v) {
        auto p = new My_node{x};
        if (i++%2) {    // choose where to insert
            root.add_left(p);
        }
        else {
            root.add_right(p);
        }
    }
}

int main() {
    std::vector<double> d{-3.457, 7.98, 10.3, 0.989};
    user(d);
	return 0;
}
