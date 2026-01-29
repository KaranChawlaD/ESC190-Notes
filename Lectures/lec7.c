#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char name[200];
    char c;
    char c1;
    double gpa;
} student;

int *create_int_block(int sz) {
    // create a block of ints of size sz and return it
    int *arr = (int *)malloc(sz * sizeof(int));
    // if malloc cannot aqllocate sz*sizeof(int) bytes for some reason
    // it returns NULL
    if (arr == NULL){
        printf("Program malloc request failed\n");
        exit(1);
    }
    return arr;
}

int *create_student_block(int sz) {
    // create a block of ints of size sz and return it
    int *arr = (student *)malloc(sz * sizeof(student));
    // if malloc cannot aqllocate sz*sizeof(int) bytes for some reason
    // it returns NULL
    if (arr == NULL){
        printf("Program malloc request failed\n");
        exit(1);
    }
    return arr;
}


int *create_int_block_bad(int sz) {
    // create a block of ints of size sz and return it
    int arr[sz];
    return arr; // will compile with a warning
                // using the adress arr might cause crash
}

int *ret_local_ptr() {
    int a;
    return &a;
}

int main() {
    // int *p = ret_local_ptr;
    // *p = 123; // also crashes
    int *block1 = create_int_block(50);
    block1[6] = 7;
    printf("6 %d\n", block1[6]);

    free(block1); // Good practice
    // not allowed to access memory at block1
}


int main1() {

    student s;
    printf("Size it takes to store student in memory: %u\n", sizeof(s));
    printf("Size it takes to store student in memory: %u\n", sizeof(student));

    student ss[50];
    ss[2].gpa = 4.0;
    printf("Size it takes to store ss in memory: %u\n", sizeof(ss));
    // total amount of spac eneedded for array ss
    printf("Space to store one s: %d\n", sizeof(ss)/50);
    printf("Num of elements in array: %d\n", sizeof(ss)/sizeof(ss[0]));

    // want a block of students using malloc
    student *s_block = (student *)malloc(sizeof(student) * 50);
    sizeof(s_block); // 8
    s_block[2].gpa = 3.0;


    return 0;
}