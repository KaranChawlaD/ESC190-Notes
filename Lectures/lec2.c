#include <stdio.h>

void change_a(int *p_a) {
    *p_a = 43;
}

void dont_change_a(int a) {
    a = 44;
}

void swap(int *p_a, int *p_b) {
    int temp;
    temp = *p_a;
    *p_a = *p_b;
    *p_b = temp;
} 

void bubble_sort(int arr[], int size) {
    int i, j;
    int temp;
    for (i=0; i < size; i++) {
        for (j=0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void print_arr(int arr[], int size) {
    int i;
    for (i = 0; i < size - 1; i++) {
        printf("%d, ", arr[i]);
    }
    if (size > 0) {
        printf("%d", arr[size-1]);
    }
    printf("\n");
}

int main() {
    printf("Hello World\n");

    int arr[] = {6, 7};
    int arr2[] = {6, 7, 6, 7};
    bubble_sort(arr2, 4);
    print_arr(arr2, 4);
    int i;

    for (i = 0; i < 2; i++) { // for i in range(2)
        printf("element %d: %d\n", i, arr[i]);
    }

    // int a = 42;
    // int *p_a = &a;

    // char *s = "abc";
    // *p_a = 43; // can also do *(&a) = 44
    // printf("%d\n", a);

    int a = 42;
    change_a(&a);
    dont_change_a(a);
    printf("%d\n", a);
    int x = 43;
    int y = 45;
    swap(&x, &y);
    printf("x is %d, y is %d\n", x, y);

    int arr3[] = {6, 7};
    // want to swap arr[0] and arr[1]
    swap(&(arr3[0]), &(arr3[1]));

    printf("%d %d\n", arr3[0], arr3[1]);

    return 0;
}