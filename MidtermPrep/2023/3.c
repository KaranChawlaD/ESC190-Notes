#include <stdio.h>
#include <stdlib.h>

typedef struct business {
    int phone_number[10]; // Note: this is an array of 10 integers
    // (one per digit), not a character array
    char *name;
} business;

void read_numbers(const char *filename, business **whitepages, int *size)
{
    FILE *fp = fopen(filename, "r");
    int c;
    *size = 0;
    while ((c = fgetc(fp)) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            *size = (*size * 10) + (c - '0');
        }
    }

    *whitepages = (business *)malloc(sizeof(business)* (*size));

    for (int i = 0; i < *size; i++) {
        int digit = 0;
        while ((c = fgetc(fp)) != '\t') {
            if (c >= '0' && c <= '9') {
                (*whitepages)[i].phone_number[digit++] = c - '0';
            }
        }
        int capacity = 64;
        int length = 0;
        (*whitepages)[i].name = (char *)malloc(sizeof(char) * capacity);
        while ((c = fgetc(fp)) != '\n' && c != EOF) {
            if (c == '\r') continue; // Domain restriction: ignore Windows CR characters
            
            // Check capacity limit, reserving 1 byte for the null terminator
            if (length + 1 >= capacity) {
                capacity *= 2; // Exponential geometric scaling to maintain O(1) amortized time
                char *temp = (char *)realloc((*whitepages)[i].name, sizeof(char) * capacity);
                if (temp == NULL) {
                    break;
                }
                (*whitepages)[i].name = temp;
            }
            (*whitepages)[i].name[length++] = (char)c;
        }
        
        // CORRECTION 3: Explicitly null-terminate the string
        (*whitepages)[i].name[length] = '\0';
    }
    
    fclose(fp);
}

int main() {
    business *businesses;
    int sz;
    read_numbers("C:\\Users\\user\\Documents\\UofT\\ESC190\\Midterm Prep\\2023\\3.txt", &businesses, &sz);
    printf("%d\n", sz);
    for (int i = 0; i < sz; i++) {
        printf("%s ", businesses[i].name);
        for (int j = 0; j < 10; j++) {
            printf("%d", businesses[i].phone_number[j]);
        }
        printf("\n");
    }
}