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
bool operator<(const N& n1, const N& n2);

template<typename N>
struct Node_base { // doesn’t know about Val (the user data)
    N* left_child;
    N* right_child;

    Node_base() : left_child{}, right_child{} {
        //std::cout << "Node_base()\n";
    }

    void insert(N* n) {

        if (!left_child)
            add_left(n);
        else {
            if (*n < *left_child) {
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

template<typename Val>
struct Node : Node_base<Node<Val>> {
    Val v;
    Node(Val v=0) : v{v} {
        //std::cout << "Node(Val v=0)\n";
    }
};

template<typename N>
bool operator<(const N& n1, const N& n2) {
    return n1.v<n2.v;
}

using My_node = Node<double>;

void user(const std::vector<double>& v)
{
    My_node root{};
    for (auto x : v) {
        root.insert(new My_node{x});
    }
}

int main() {
    std::vector<double> d{-3.457, 7.98, 10.3, 0.989};
    user(d);
	return 0;
}
