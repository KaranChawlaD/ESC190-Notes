#include <stdio.h>

char *strcat_rec(char *dest, const char *src) {
    // Phase 1: Traverse to the end of the destination string
    if (*dest != '\0') {
        strcat_rec(dest + 1, src);
    } 
    // Phase 2: Copy the source string character by character
    else if (*src != '\0') {
        *dest = *src;
        *(dest + 1) = '\0'; // Lookahead termination prevents reading uninitialized memory
        strcat_rec(dest + 1, src + 1);
    }
    
    return dest; // Ensures the original pointer is preserved and passed back up the call stack
}

int main() {
    char dest[200] = "Hello";
    char *src = "Bye";
    char *res;
    res = strcat_rec(dest, src);
    printf("%s", res);
    return 0;
}