#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student1 {
    char name[200];
    int age;
} student1;

typedef struct student2 {
    char *name;
    int age;
} student2;

typedef struct student3 {
    const char *name;
    int age;
} student3;

void change_name_1(student1 *s1) {
    // s1->name = "mike";       // not allowwed because cannot assign to arrays
    strcpy(s1->name, "mike");   // allowed
                                // allowed to write and modify contents of arrays
}

void change_name_2(student2 *s2) {
    //s2->name = "mike";            // allowed: you can change the value of address name to smth else
    strcpy(s2->name, "mike");       // depends: if s2->name is actually an address of a string literal, may crash
}

void change_name_3(student3 *s3) {
    //s2->name = "mike";            // allowed: you can change the value of address name to smth else
    strcpy(s3->name, "mike");       // depends: if s2->name is actually an address of a string literal, may crash
}

int main1() {
    student2 st2; //st2.name is some random number, st2.age is also some random number
    //change_name_2(&st2); //BAD: you're trying to write "Mike" to the random address st2.name
    
    student2 st2a = {"Michael", 41};
    //change_name_2(&st2a); //st2.name is the address of the "M" in "Michael", but "Michael" is a string literal

    char name[] = "Michael";
    st2a.name = name;
    change_name_2(&st2a); // FINE: st2a.name is now the address of the "M" in the array name, allowed to modify contents

    char *name2 = (char *)malloc(sizeof(char) * 200);
    st2a.name = name2;
    change_name_2(&st2a);

    student3 st3 = {"Michael", 41};
    // st3.name[0] = 'm'; // not allowed to modify, won't compile
    // change_name_2(&st3); // crash
    // change_name_3(&st3); // crash but will compile
}

void create_student2(student2 **p_s2, const char *name, int age) {
    *p_s2 = (student2 *)malloc(sizeof(student2));
    (*p_s2)->age = age;
    (*p_s2)->name = (char *)malloc(sizeof(char) * strlen(name) + 1);
    strcpy((*p_s2)->name, name);
}

student2* create_student2v2(const char *name, int age) {
    student2 *s2 = (student2 *)malloc(sizeof(student2));
    s2->age = age;
    s2->name = (char *)malloc(sizeof(char) * strlen(name) + 1);
    strcpy(s2->name, name);
    return s2;
}

void destroy_student2(student2 *s2) {
    free(s2->name);
    free(s2);
}

int main() {
    student2 *s2;
    create_student2(&s2, "Mike", 41);
    printf("Name: %s\n", s2->name);
    s2->name[0] = 'm';
    printf("Name: %s\n", s2->name);
    // s2 a pointer to a student with the name "Mike" and age 31

    free(s2);
}