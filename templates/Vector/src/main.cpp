/*
 * main.cpp
 *
 *  Created on: Jan 8, 2022
 *      Author: osboxes
 */


template<typename T>
class Vector {
    T* v;
    int sz;

public:
    Vector() : Vector(0) {}
    explicit Vector(int n) : v{new T[n]}, sz{n} {}
};

template<>
class Vector<void*> {
    void** p;
    void*& operator[](int i) { return *p[i]; }
};

template<typename T>
class Vector<T*> : private Vector<void*> {
public:
    using Base = Vector<void*>;

    Vector() {}
    explicit Vector(int i) : Base(i) {}
    T*& elem(int i) { return reinterpret_cast<T*&>(Base::elem(i)); }
    T*& operator[](int i) { return reinterpret_cast<T*&>(Base::operator[](i)); }
};

int main() {

}
