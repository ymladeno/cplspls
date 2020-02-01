//============================================================================
// Name        : raii.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>

class File_ptr {
    FILE* file;

public:
    File_ptr(const char * p_name, const char * p_mode)
    : file{std::fopen(p_name, p_mode)} {
        if (nullptr == file) {
            throw std::runtime_error("Cannot open a file");
        }
        std::cout << __func__ << std::endl;
    }

    ~File_ptr() {
        std::cout << __func__ << std::endl;
        fclose(file);
    }
};

static void foo() {
    File_ptr f{"hi.txt", "r"};
}

int main()
{
    foo();
}
