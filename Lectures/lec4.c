#include <stdio.h>
#include <string.h>

int main() {
    // int a = 67;
    // int *p_a = &a; // p_a is the address where a is stored
    // printf("%d %d\n", a, *p_a);
    // printf("%d %d\n", a, *(&a));
    // printf("%d", *(&(*(&a))));
    char *s1 = "abc";
    char s2[] = "abc";

    s1 = "xyz"; //allowed, s1 is now the address of the x
    // s2 = "xyz"; //not allowed; will produce error

    // s1[0] = 'a'; // will not always produce compile error, but program could crash

    s2[0] = 'x'; // fine

    printf("%s\n%s\n", s1, s2);

    printf("%s\n", s2);

    int i = 0;
    while (s2[i] != '\0') {
        printf("%c", s2[i]);
        i++;
    }
    
    printf("\n");

    printf("%d\n", strlen(s2));
    return 0;
}