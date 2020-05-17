//============================================================================
// Name        : template_obj_holder.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>

template<typename T>
struct On_heap {
    // allocate
    On_heap() : p(new T) { }
    // deallocate
    ~On_heap() { delete p; }

    T& operator*()  { return *p; }
    T* operator->() { return p;  }
    T& operator[](int i)  { return p[i]; }

    // prevent copying
    On_heap(const On_heap&) = delete;
    On_heap operator=(const On_heap&) = delete;

    On_heap operator=(const double) { return *this; }

private:
    // pointer to object on the free store
    T* p;
};

template<typename T>
struct Scoped {
    T& operator*() { return x; }
    T* operator->() { return &x; }

    Scoped() : x{} {}
    // prevent copying
    Scoped(const Scoped&) = delete;
    Scoped operator=(const Scoped&) = delete;

private:
    T x; // the object
};

constexpr int on_stack_max = sizeof(std::string);

template<typename T>
struct Obj_holder {
    using type = typename std::conditional<(sizeof(T)<=on_stack_max),
                            Scoped<T>, // first alternative
                            On_heap<T> // second alternative
                            >::type;
};

template<typename T>
using Holder = typename Obj_holder<T>::type;

void f2()
{
    // the double goes on the stack (scoped)
    Holder<double> v1;

    // the array goes on the free store (on heap)
    Holder<std::array<double ,200>> v2;

    // ...
    *v1 = 7.7;    // Scoped provides pointer-like access (* and [])
    v2[77] = 9.9; // On_heap provides pointer-like access (* and [])
    // ...
}

int main() {
    f2();
	return 0;
}
