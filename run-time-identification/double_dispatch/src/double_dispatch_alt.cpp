/*
 * double_dispatch_alt.cpp
 *
 *  Created on: Apr 23, 2020
 *      Author: osboxes
 */

struct Rectangle {

};

class Shape {
public:
    virtual Rectangle box() const = 0; // the rectangle encloses the shape
    // ...
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    Rectangle box() const override;
    // ...
};

class Triangle : public Shape {
public:
    Rectangle box() const override;
    // ...
};

bool intersect(const Rectangle&, const Rectangle&);     // simple to calculate

//bool intersect(const Shape& s1, const Shape& s2)
//{
//    return intersect(s1.box(),s2.box());
//}

bool intersect(const Shape& s1, const Shape& s2)
{
    auto i = index(type_id(s1),type_id(s2));
    return intersect_tbl[i](s1,s2);
}

int main() {

}
