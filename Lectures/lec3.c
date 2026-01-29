#include <stdio.h>

void f(int *p_a) {
    *p_a = 43;
}

void change_a(int *p_a) {
    *p_a = 42;
}

void dont_change_a(int a) {
    a = 43;
}

void change_arr0(int *arr0) {
    *arr0 = 42;
}

int main() {
    // int a = 43;
    // char *s = "xyz";
    // int *p_a = &a;

    // printf("%s %d", s, *p_a);

    // int a = 42;
    // int *p_a = 0;
    // p_a = &a; // *p_a is the same as a
    // *p_a = 45; // the value of a is now 45

    // // aliasing in C
    // int *another_p_a = p_a;
    // *another_p_a = 46; // a is now 46, a can also be accessed through *another_p_a

    // int b = 44;
    // f(&b);

    // printf("%d\n", b);
    
    // char *p = "hi";
    // printf("%s\n", p+1);

    // int arr[] = {3, 4};
    // printf("%d\n", *(arr+1));

    // int a;
    // change_a(&a);

    // printf("%d\n", a);

    // dont_change_a(a);

    // printf("%d\n", a);

    int arr[3] = {5, 6, 7};
    change_arr0(&(arr[0])); // or just arr

    printf("%d\n", arr[0]);

    return 0;
}