/*
 * List.hpp
 *
 *  Created on: Apr 7, 2020
 *      Author: osboxes
 */

#ifndef LIST_HPP_
#define LIST_HPP_

class Underflow {

};

template<class T>
class List {
public:
    void insert(T);
    T get();

    // ...
    class Underflow {};

private:
    struct Link {
        T val;
        Link* next;
    };
    struct Chunk {
        enum { chunk_size = 15 };
        Link v[chunk_size];
        Chunk*  next;
    };

    Chunk*  allocated;
    Link*   free;
    Link*   get_free();
    Link*   head;
};

template<typename T>
void print_all(const List<T>);

#endif /* LIST_HPP_ */
