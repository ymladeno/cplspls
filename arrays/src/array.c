/*
 * array.cpp
 *
 *  Created on: May 4, 2020
 *      Author: osboxes
 */

#include <stdio.h>

//for function parameter array is always a pointer
int mango[100];

void arr(const char p[]) {
    printf("%s\n", p);
    mango[0] = 1000;
}
