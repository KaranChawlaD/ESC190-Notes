#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[200];

    char number[11];
    double GPA;
} student;

int main() {
    typedef int sz;

    sz size = 15;

    printf("%d\n", size);

    student s1 = {"John Doe", "1234567890", 3.3};
    printf("%s, %.1f\n", s1.name, s1.GPA);
    student *p_s1 = &s1;
    printf("%s, %.1f\n", p_s1->name, p_s1->GPA);

    int *block_int = (int *)malloc(sizeof(int) * 150);

    block_int[7] = 42;

    student *p_arr = (student *)malloc(3 * sizeof(student));
    strcpy(p_arr[0].name, "Bob"); // basically p_array[0].name[0] = 'B' ...
    strcpy(p_arr[0].number, "2345678910");
    p_arr[0].GPA = 3.5;

    printf("Name: %s, GPA: %.1f\n", p_arr[0].name, p_arr[0].GPA);
    
    //sizeof - used for finding space taken by a type

    return 0;
}