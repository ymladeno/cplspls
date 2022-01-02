//============================================================================
// Name        : List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "List.hpp"

int main() {
    List<int> list{10,5,3};

    list.insert(2);
    print_all(list);

	return 0;
}
