/*
 * List.hpp
 *
 *  Created on: Apr 26, 2020
 *      Author: osboxes
 */

#ifndef LIST_HPP_
#define LIST_HPP_

template<typename T>
class Link;

template<typename T>
struct Iterator {
    Link<T>* current_position;
};

template<typename T>
class Link {
    template<typename U, typename A>
        friend class List;
    T val;
    Link* succ;
    Link* prev;
};

template<typename T, typename A>
class List {
public:
    void insert(T);
    T get();
    // ...
    class Underflow {};

    Iterator<T> begin();
    Iterator<T> end();

private:

    Link*   free;
    Link*   get_free();
    Link*   head;
};

#endif /* LIST_HPP_ */
