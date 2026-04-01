#include <stdio.h>

int f(int x) {
    return 41;
}

int main() {
    printf("%ld\n", f);
    printf("%d\n", f(12));
}