//============================================================================
// Name        : io_obj.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <functional>
#include <fstream>

class Io_obj {
public:
    virtual Io_obj* clone() const = 0;
    virtual ~Io_obj() {}
};

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() {}
    // ...
};

class Circle : public Shape {
public:
    void draw() const override { std::cout << "Draw circle\n"; }
    // ...
};

class Unknown_class {

};

template<class T>
struct Io : T, Io_obj {
//    T val;
    Io(std::istream&) { /*empty implementation for now*/ }      //initialize from input stream
    Io* clone() const override          { return new Io{*this}; }
    static Io* new_io(std::istream& is) { return new Io{is}; }  // for io_map
};

std::string get_word(std::istream& is) {
    std::string w{};
    is >> w;
    return w;
}

using Pf = std::function<Io_obj*(std::istream&)>;
using Io_Circle = Io<Circle>;
//std::map<std::string, Pf> io_map = {
//        {"Io_circle", &Io_Circle::new_io}
//};

void f(Io<Shape>& ios)
{
    Shape* ps = &ios;
    // ...
}

Io_obj* get_obj(std::istream& is)
{
//    std::string str = get_word(is);     // read initial word
//    if (auto f = io_map[str])           // look up str to get function
//        return f(is);                   // call function
//    throw Unknown_class{};              // no match for str
    return nullptr;
}

//template<typename T>
//T* get_val<T>(Io_obj* p)
//{
//    if (auto pp = dynamic_cast<Io<T>*>(p))
//        return &pp->val;
//    return nullptr;
//}

template<typename T>
T* get_val<T>(Io_obj* p) {
    return nullptr;
}

int main() {
    Io_Circle myCircle{std::cin};

    // ... open file assumed to hold shapes, and attach ss as an istream for that file ...
    std::ifstream ss{"temp"};

    std::unique_ptr<Io_obj> p {get_obj(ss)};            // read object from stream
    if (auto sp = get_val<Shape>(p.get())) {
        sp->draw(); // use the Shape
        // ...
    }
    else {
        // ... oops: cope with non-shape in Shape file ...
    }

	return 0;
}
