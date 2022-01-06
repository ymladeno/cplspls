/*
 * List.cpp
 *
 *  Created on: Apr 7, 2020
 *      Author: osboxes
 */

#include "List.hpp"

template<class T>
void List<T>::insert(T val)
{
    Link* lnk = get_free();
    lnk->val  = val;
    lnk->next = head;
    head = lnk;
}

template<class T>
T List<T>::get()
{
    if (head == 0)
        throw Underflow{};              // Underflow is my exception class
    Link*   p= head;
    head =  p->next;
    p->next = free;
    free = p;
    return p->val;
}

template<class T>
auto List<T>::get_free()->Link*
{
    if (free == 0) {
        free = new Link{};
    }

    Link*   p = free;
    free =  free->next;
    return p;
}

template<typename T>
void print_all(List<T> l) {
    try {
        while(true) {
            auto val = l.get();
            std::cout << val << " ";
        }
    } catch(const Underflow& e) {
        std::cout << "\n";
    }
}
