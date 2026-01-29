// PONG results

// Syllabus

// C is a compiled language (Hardware language) vs Python is a interpreted language (Software language)
// C exposes how code "really" runs on a computer

#include <stdio.h>

int main()
{
    int x = 190; // int: type. in C, have to declare the type
    char *prof = "Evan Bentz"; // char* *kind of a string*
                               // prof is the address where the 'E' is stored
    // printf("Hello World, x = %d\n", x); // integer
    // printf("Prof. %s\n", prof); // "string"
    char c = '@';
    char *p_c = &c;
    printf("%c\n", c); // character
    printf("%ld %ld\n", p_c, &c); // long decimal
    printf("%ld\n", prof); // since prof is an address
    return 0;
}

/* Types:
 int
 double
 char: a character
 int *: address of int
 char *: address of char */

// C does not have a string type, holds each charter in different memory
// ends with a special char (null character)

// long int
// & - means "address of"

/* // Arrays
int arr[] = {5, 10, 2}; // braces for intialization
arr[0] = 3;

int arr2[10]; // array of size 10

// cannot say: arr = {1, 2, 3} //can only use {} for initialization */