#include <string>
#include <iostream>

template<typename T>
void foo(T&& s) {
    // Use static_assert to check the type
    std::cout << s << "\n";
}

int main() {
    int a = 10;
    foo(a);
    foo(20);
}

// Array can't be passed by value