#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student1 {
    char name[200]; // cannot assign to name: name = ... disallowed
    int age;        // can modify the contents of name
} student1;

typedef struct student2 {
    char *name;     // can assign to name: name = ... allowed
    int age;        // can modify the contents of name, but may not work (writeability)
} student2;

typedef struct student3 {
    const char *name;   // can assign to name
    int age;            // cannot modify the contents of name (will not compile)
} student3;

void change_name1(student1 st1)
{
    st1.name[0] = 'm';
}

void change_name2(student2 st2)
{
    st2.name[0] = 'm';
}

void change_name3(student3 st3)
{
    // st3.name[0] = 'm'; // won't compile
}

void change_name1a(student1 st1)
{
    // st1.name = "m"; // not allowed, st1 is an array
}

void change_name2a(student2 st2)
{
    st2.name = "m"; // will compile, will not have an effect
}

void change_name3a(student3 st3)
{
    st3.name = "m"; // will compile, will not have an effect
}

void change_name1b(student1 *p_s1)
{
    // p_s1->name = "m"; // still an array, will not compile
}

void change_name2b(student2 *p_s2)
{
    p_s2->name = "m"; // will compile, will have an effect
}

void change_name3b(student3 *p_s3)
{
    p_s3->name = "m"; // will compile, will have an effect
}

void change_name1c(student1 *p_s1)
{
    strcpy(p_s1->name, "m"); // fine
}

void change_name2c(student2 *p_s2)
{
    strcpy(p_s2->name, "m"); // fine
}

void change_name3c(student3 *p_s3)
{
    // strcpy(p_s3->name, "m"); // not fine, will compile but may crash
}

void change_name1d(student1 st1)
{
    strcpy(st1.name, "m"); // will compile, but no effect
}

void change_name2d(student2 st2)
{
    strcpy(st2.name, "m"); // will compile, will have an effect
}

void change_name3d(student3 st3)
{
    strcpy(st3.name, "m"); // will compile, will crash
}

// blocks of structs, blocks of pointers to structs

int main() 
{
    // create a block of 50 student1's using malloc
    student1 *s1_block = (student1 *)malloc(sizeof(student1)*50);
    // change the name of student #3 in s1_block
    change_name1c(&(s1_block[3])); // or change_name1c(s1_block + 3)

    // create a block of 50 student2's using malloc
    student2 *s2_block = (student2 *)malloc(sizeof(student2)*50);
    // change the name of student #3 in s2_block
    change_name2b(&(s2_block[3])); // or change_name2b(s1_block + 3)

    return 0;
}



int main1() 
{
    student1 st1 = {"Mike", 31};
    change_name1(st1);

    char name[] = "Mike";
    student2 st2 = {name, 31};
    change_name2(st2);
    change_name4(st2);
    printf("%s, %s\n", st1.name, st2.name);
    return 0;
}