#include <stdio.h>
#include <stdlib.h>

void make_str(char **p_s) {
    *p_s = (char *)malloc(10001);
    for (int i = 0; i < 10000; i++) {
        (*p_s)[i] = (i % 10) + '0';
    }
    (*p_s)[10000] = '\0';
}

int main() {
    char *s;
    make_str(&s);
    printf("%s\n", s);

    printf("%d", atoi("86\n"));
}