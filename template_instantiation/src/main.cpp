//============================================================================
// Name        : template_instantiation.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//https://stackoverflow.com/questions/44335046/how-does-the-linker-handle-identical-template-instantiations-across-translation?answertab=votes#tab-top

#include <iostream>

extern unsigned foo();
extern unsigned boo();

int main()
{
    std::cout << std::hex
    << '\n' << foo()
    << '\n' << boo()
    << std::endl;
    return 0;
}
