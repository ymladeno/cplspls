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
#include <queue>

struct Red_black_balance {
    template<typename N>
    bool compare(const N& n1, const N& n2) {
        std::cout << "cmp: " << "n1: " << n1.v << " " << "n2: " << n2.v << "\n";
        return n1.v<n2.v;
    }
};


template<typename N, typename Balance>
struct Node_base : Balance {
    N* left_child;
    N* right_child;

    Node_base() : left_child{}, right_child{} {
    }
    // Node_base(const N& o) : left_child{ new N{o.left_child}}, right_child{ new N{o.right_child}} {}
    void insert(N* n) {
        std::cout << "Insert: " << n->v << "\n";
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
        std::cout << "Exit insert\n";
    }

private:
    void add_left(N* p)
    {
        std::cout << "add left\n";
        if (left_child == nullptr)
            left_child = p;
        else {
            left_child->insert(p);
        }
    }

    void add_right(N* p)
    {
        std::cout << "add right\n";
        if (right_child == nullptr)
            right_child = p;
        else {
            right_child->insert(p);
        }
    }
};

template<typename Val, typename Balance>
struct Node : public Node_base<Node<Val, Balance>, Balance> {
    using balance_type = Balance;

    Node(Val v=0) : v{v} {
        //std::cout << "Node(Val v=0)\n";
    }

    Node(const Node& o) : Node_base<Node<Val, Balance>, Balance>{o}, v{o.v} {}
    Val v;
};

template<typename T>
using Rbnode = Node<T, Red_black_balance>;

template<typename T>
void print(const T& t);

template<>
void print(const Rbnode<double>& node) {
    const auto left = node.left_child;
    const auto right = node.right_child;

    std::queue<Rbnode<double>*> q{};
    q.push(left);
    q.push(right);

    while(!q.empty()) {
        auto node = q.front();
        std::cout << node->v << " ";
        q.pop();

        if (node->left_child != nullptr) {
            q.push(node->left_child);
        }

        if (node->right_child != nullptr) {
            q.push(node->right_child);
        }
    }
    std::cout << "\n";
}

void user(const std::vector<double>& v)
{
    Rbnode<double> root{};
    for (auto x : v) {
        root.insert(new Rbnode<double>{x});
    }

    print(root);
}

int main() {
    std::vector<double> d{3.457, 7.98, 10.3, 0.989, 102.3, 99.8};
    user(d);
	return 0;
}
