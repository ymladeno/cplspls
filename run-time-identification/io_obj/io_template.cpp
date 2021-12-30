#include <string>
#include <iostream>
#include <map>
#include <functional>

class Shape {

};

class Circle : public Shape {
public:
    Circle(std::istream& is) { std::string w; is >> w; std::cout << w << std::endl; }
};

template<typename T>
class Io {
public:
    Io(std::istream& is) {}
};

// conversion from Io<Circle> to Io<Shape> is not allowed
// if it's needed it could be defined
void foo(Io<Shape>& Io) {

}

int main()
{
    Io<Circle> c{std::cin};
    foo(c);
}
