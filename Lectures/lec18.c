#include <stdio.h>
#include <stdlib.h>

void set_even_to_zero(int *block, int size) {
    int i;
    for (i = 0; i < size; i+= 2) {
        block[i] = 0;
    }
}

int main() {
    int array[] = {5, 6, 7, 8};
    int size = 4;
    printf("Before: ");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
    }

    printf("\n");

    set_even_to_zero(array, size);

    printf("After: ");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
    }
}