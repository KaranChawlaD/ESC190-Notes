// valgrind
// a tool for detecting memory errors and leaks
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lec13-funcs.h"
#include "lec13-mystr.h" // copy past functions

// int main1() 
// {
//     int *arr = (int *)malloc(10000 * sizeof(int));
//     // free(arr);
//     printf("hi\n"); // run valgrind ./lec13

//     //printf("%d\n", arr[10000]); // undefined behaviour
//     if (arr[0] > 0) {
//         printf("I LOVE PRAXIS\n");
//     }
//     free(arr);
// }

// header files

// int main2() {
//     printf("%d\n", f42());
// }

// implement something like Python strings

int main() {
    mystr *s1;
    create_string(&s1, "Hi");
    printf("Done");
}