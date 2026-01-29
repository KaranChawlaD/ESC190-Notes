#include <stdio.h>
#include <stdlib.h>

void change_p_a(int **p_p_a) {
    *p_p_a = (int *)malloc(sizeof(int));
    // Breaks the aliasing
}

int main() {
    int a = 4;
    int *p_a = &a;
    printf("before: %ld\n", p_a);
    printf("a = %d, *p_a = %d\n", a, *p_a);
    change_p_a(&p_a);
    printf("after: %ld\n", p_a);
    *p_a = 5;
    printf("a = %d, *p_a = %d\n", a, *p_a);
    int *p_b = p_a;
    *p_b = 6;
    printf("a = %d\n", a); // 42
    printf("*p_a = %d\n", *p_a);
    printf("*p_b = %d\n", *p_b);


    return 0;
}