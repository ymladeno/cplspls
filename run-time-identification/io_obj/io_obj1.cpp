/*
 * io_obj1.cpp
 *
 *  Created on: Dec 27, 2021
 *      Author: osboxes
 */

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <functional>

class Io_obj {
public:
    virtual Io_obj* clone() const = 0;
    virtual ~Io_obj() {}
};

class Shape : public Io_obj {

};

struct Circle {};
struct Triangle{};

struct Io_circle : Circle, Io_obj {
    Io_circle(std::istream& is) { std::cout << "creare new circle\n"; }
    Io_circle *clone() const { return new Io_circle{*this}; }
    static Io_obj* new_circle(std::istream& is) { return new Io_circle{is}; }
};

class Unknown_class {

};

class Io_triangle : public Triangle, public Io_obj {
public:
    Io_triangle(std::istream& is) { std::cout << "creare new triangle\n"; }
    Io_triangle *clone() const { return new Io_triangle{*this}; }
    static Io_obj* new_triangle(std::istream& is) { return new Io_triangle{is}; }
};

using Pf = std::function<Io_obj*(std::istream&)>;
std::map<std::string, Pf> io_map = {
        {"Io_circle", &Io_circle::new_circle},
        {"Io_triangle", &Io_triangle::new_triangle}
};

std::string get_word(std::istream& is) {
    std::string w{};
    is >> w;
    return w;
}

Io_obj* get_obj(std::istream& is) {
    std::string str = get_word(is);
    if(auto f = io_map[str]) {
        return f(is);
    }
    throw Unknown_class{};
}

int main() {
    std::ifstream f = std::ifstream("temp");
    Io_obj* po = get_obj(f);
}
