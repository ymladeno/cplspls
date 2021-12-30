//============================================================================
// Name        : double_dispatch.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <utility>

class Circle;
class Triangle;

class Shape {
public:
    virtual bool intersect(const Shape&   ) const =0;
    virtual bool intersect(const Circle&  ) const =0;
    virtual bool intersect(const Triangle&) const =0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    bool intersect(const Shape&  s) const override { std::cout << "CircleShape\n"; return s.intersect(*this); }
    bool intersect(const Circle&  ) const override { std::cout << "intersect(circle,circle)\n"; return true;   }
    bool intersect(const Triangle&) const override { std::cout << "intersect(circle,triangle)\n"; return true; }
};

class Triangle : public Shape {
public:
    bool intersect(const Shape&  s) const override { std::cout << "TriangleShape\n"; return s.intersect(*this); }
    bool intersect(const Circle&  ) const override { std::cout << "intersect(triangle,circle)\n"; return true;   }
    bool intersect(const Triangle&) const override { std::cout << "intersect(triangle,triangle)\n"; return true; }
};

void test(Triangle& t, Circle& c)
{
    std::vector<std::pair<Shape*,Shape*>> vs { {&t,&t}, {&t,&c}, {&c,&t}, {&c,&c} };

    for (auto p : vs)
        p.first->intersect(*p.second);
}

int main() {
    Triangle t;
    Circle c;

    test(t, c);

	return 0;
}
