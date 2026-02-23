#include <stdio.h>
#include <string.h>

int last_occurrence(char *str1, char *str2) {
    int len_1 = strlen(str1);
    int len_2 = strlen(str2);
    int res = -1;

    for (int i = 0; i < len_1 - len_2 + 1; i++) {
        for (int j = 0; j < len_2; j++) {
            if (str1[i+j] != str2[j]) break;
            else if (j == len_2-1) {
                res = i;
            }
        }
    }

    return res;
}

int main() {
    char str1[] = "EngSciEngSciTrackOne";
    char str2[] = "EngSci";
    int res = last_occurrence(str1, str2);

    printf("%d\n", res);
}