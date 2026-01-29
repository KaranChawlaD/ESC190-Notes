#include <stdio.h>

char *strcpy(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return dest;
}

int main() {
    return 0;
}