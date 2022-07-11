/*
 * utility.hpp
 *
 *  Created on: Dec 12, 2020
 *      Author: osboxes
 */

#ifndef UTILITY_HPP_
#define UTILITY_HPP_

#include <stdexcept>

namespace ipr {
namespace util {

// template<typename T>
// inline T* check(T* ptr) {
//     if (ptr == nullptr)
//         throw std::logic_error("attemp to derefence a null pointer");
//     return ptr;
// }

// namespace rb_tree {
// template<typename Node>
// struct link {
//     enum Color {Black, Red};
//     enum Dir {Left, Right, Parent};

//     link() : arm(), color(Red) {}
//     Node* arm[3];
//     Color color;
// };

// template<typename T>
// struct node : link<node<T>> {
//     T data;
// };

// template<typename T>
// struct container {
//     template<typename Ket, class Comp>
//     T* insert(const Key&, Comp) const;
// private:
//     Node* root;

//     node<T>* allocate() {
//         return static_cast<node<T>*>(operator new (sizeof(node<T>)));
//     }
//     template<class U>
//     node<T>* make_node(const U& u) {
//         node<T>* n = allocate();
//         return n;
//     }
// };

// template<typename T>
// template<typename Key, class Comp>
// T* container<T>::insert(const Key& key, Comp comp) {

// }
// }
}
}

#endif /* UTILITY_HPP_ */
