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

int main() {
    String<char> s ("abcdefghij");
    std::cout << s << '\n';
    s += 'k';
    s += 'l';
    s += 'm';
    s += 'n';
    std::cout << s << " size=" << s.size() << std::endl;

    String<char> s2 = "Hell";
    s2 += " and high water";
    std::cout << s2 << '\n';

    String<char> s3 = "qwerty";
    s3 = s3;

    String<char> s4 = "the quick brown fox jumped over the lazy dog";
    s4 = s4;
    std::cout << s3 << " " << s4 << "\n";
    std::cout << s + ". " + s3 + String<char>(". ") + "Horsefeathers\n";

    String<char> buf;
    while (std::cin>>buf && buf!="quit") {
        std::cout << buf << " " << buf.size() << " " << buf.capacity() << '\n';
    }
	return 0;
}
