//============================================================================
// Name        : template_string.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "String.hpp"
#include "String.cpp"
//#include <string>

int main() {
    String<char> s ("abcdefghij");
    std::cout << s << '\n';
    s += 'k';
    s += 'l';
    s += 'm';
    s += 'n';
    std::cout << s << " size=" << s.size() << std::endl;

    String<char> s2 = String<char>("Hell");
    s2 += String<char>(" and high water");
    std::cout << s2 << '\n';

    String<char> s3 = String<char>("qwerty");
    s3 = s3;

    String<char> s4 = String<char>("the quick brown fox jumped over the lazy dog");
    s4 = s4;
    std::cout << s3 << " " << s4 << "\n";
    std::cout << s + String<char>(". ") + s3 + String<char>(". ") + String<char>("Horsefeathers\n");

    String<char> buf;
    while (std::cin>>buf && buf != String<char>("quit")) {
        std::cout << buf << " " << buf.size() << " " << buf.capacity() << '\n';
    }
    return 0;
}
