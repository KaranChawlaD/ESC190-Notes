#include <stdio.h>

int first_occurrence(char *str1, char *str2, int index1, int index2) {
    if (str2[index2] == '\0') {
        return index1 - index2;
    }
    else if (str1[index1] == '\0') {
        return -1;
    }
    else if (str1[index1] == str2[index2]) {
        return first_occurrence(str1, str2, index1 + 1, index2 + 1);
    }
    else {
        return first_occurrence(str1, str2, index1 - index2 + 1, 0);
    }
}

int main() {
    char str1[] = "aEngSci EngSci TrackOne";
    char str2[] = "EngSci";

    printf("%d\n", first_occurrence(str1, str2, 0, 0));
}