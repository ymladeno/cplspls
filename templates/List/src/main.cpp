//============================================================================
// Name        : List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "List.hpp"
#include "List.cpp"

int main() {
    List<int> list{};

    list.insert(2);
    list.insert(10);
    list.insert(3);
    print_all(list);

	return 0;
}
