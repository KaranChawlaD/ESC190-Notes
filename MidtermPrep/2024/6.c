#include <string.h>

char *generate_strings(char *alphabet, int k) {
    int count = 1;
    int len = strlen(alphabet);

    for (int i = 0; i < k; i++) {
        count *= len;
    }

    char res[2*count + 1];

    int digit = 0;

    while (digit < count) {
        digit ++;
    }
}