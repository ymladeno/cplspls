/*
 ============================================================================
 Name        : reference_array_pointer_bug_c.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// extern int* mango;
extern int mango[];

int main(void) {
    const char* p = "glatemala";
    arr(p);

    // In case mango is a pointer, it tryies to read from address 1000
    if (1000 == mango[0]) {
        printf("yes");
    }
    printf("%d", mango[0]);
    // printf("%d", sizeof(mango));
	return EXIT_SUCCESS;
}
