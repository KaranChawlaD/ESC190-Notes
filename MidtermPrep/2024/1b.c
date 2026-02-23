#include <stdio.h>

int sum_odd(int *arr, int sz) {
    int res = 0;
    for (int i = 0; i < sz; i++) {
        if (arr[i] % 2 == 1) {
            res += arr[i];
        }
    }
    return res;
}

int main() {
    int arr[] = {4, 3, 2, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", sum_odd(arr, n));
}