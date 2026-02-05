#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcpy_annoying(char *dest, const char *src) {
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
}

char *my_strcpy_annoying_and_elegant(char *dest, const char *src) {
    while (*dest++ = *src++);
}

int main() {
    int a = 42;
    int b = a++; // b is 42, a is 43
    int c = ++b; // c is 43, b is 43

    printf("%d %d %d\n", a, b, c);

    char *str1 = (char *)malloc(10);
    strcpy(str1, "abc");

    char *str2 = (char *)malloc(10);
    strcpy(str2, "xyz");

    printf("str1: %ld, str1: %s\n", str1, str1);
    printf("str2: %ld, str2: %s\n", str2, str2);
    *str1++ = *str2++;
    printf("str1: %ld, str1: %s\n", str1, str1); //bc
    printf("str2: %ld, str2: %s\n", str2, str2); //yz
    printf("old str1: %s", str1-1); //xbc
}