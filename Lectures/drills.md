### Q1. Define an integer variable a and initialize it to 42
```c
int a = 42;
```

### Q2. Define a pointer to an integer variable p_a and initialize it to the address of a
```c
int *p_a = &a;
```

### Q3. Using p_a and without directly using a, change the value of a to 43
```c
*p_a = 43;
```

### Q4. Change the value of the pointer p_a to something else. Make sure that the value of a does not change
```c
int b = 44;
p_a = &b;
```

### Q5. Define a function that takes in a pointer to an integer and changes the integer
```c
void change_int(int *p_int) {
    *p_int = 45;
}
```

### Q6. Call the function from Q5 and pass in the address of a. Make sure that the value of a changes
```c
change_int(&a);
```

### Q7. Call the function named change_int without directly using a, but using p_a instead
```c
change_int(p_a);
```

### Q8. Define a variable that would store the address of p_a
```c
int **p_p_a;
```

### Q9. make p_p_a point to p_a
```c
p_p_a = &p_a;
```

### Q10. Write a function that takes in a pointer to a pointer to an integer and changes the value of the integer to 46
```c
void change_int2(int **p_p_int) {
    **p_p_int = 46; 
}

change_int2(p_p_a);
// OR
change_int2(&p_a);
```

### Q11. Write a function that takes in a pointer to a pointer to an integer and changes the value of the pointer to a new address where an integer can be stored. (You will need to use malloc)
```c
void change_p_a(int **p_p_a) {
    *p_p_a = (int *)malloc(sizeof(int));
}

int main() {
    int *p_a = (int *)malloc(sizeof(int));
    *p_a = 4;
    change_p_a(&p_a);
    *p_a = 5;
}
```

### Q12. Call the function from Q10 in order to change the value of a to 46. Do this using p_p_a, and using p_a.
```c
change_int2(p_p_a);
// OR
change_int2(&p_a);
```

### Q13. Call the function from Q11 in order to change the value of p_a to point to a new address. Don't use p_p_a.
```c
change_p_a(&p_a);
```
### Q14. Call the function from Q11 in order to change the value of p_a to point to a new address. Use p_p_a.
```c
change_p_a(p_p_a);
```
### Q15. Declare an array of integers and initialize it to {5, 6, 7}
```c
int arr[3] = {5, 6, 7};
```
### Q16. Write a function that takes in a pointer to the first element of an array of integers and modifies the element at index 2 to 8
```c
void change_arr(int *arr) {
    *(arr+2) = 8;
}
```
### Q17. Call the function from Q16 in order to change the value of an element of the array from Q15
```c
change_arr(arr);
```
### Q18. Create a malloc-allocated block of memory that can store 3 integers. Store the address in the variable p_block. Then use change_arr to change the value at index 2
```c
int *p_block = (int *)malloc(sizeof(int)*3);
change_arr(p_block);
```
### Q19. Use change_int from Q5 to change the value of the integer stored in the block of memory from Q18
```c
change_int(p_block + 2);
```
### Q20. Use change_int_ptr from Q11 to change the value of p_block to point to a new address
```c
change_int_ptr(&p_block);
```

### Q21. Create an object of type student, with char name[1000] and int age, and initialize it
```c
typedef struct student {
    char name[1000];
    int age;
} student;

int main() {
    student s1 = {"Mike", 41};
    return 0;
}
```
### Q22. Change the name of the student to "Jennifer"
```c
    #include <string.h>
    strcpy(s1.name, "Jennifer");
```
### Q23. Change the age of the student to 21
```c
    s1.age = 21;
```
### Q24. Create a pointer p_s to the student and initialize it to the address of the student
```c
    student *p_s1 = &s1;
```
### Q25. Change the name of the student to "Jenny", using p_s
```c
    strcpy(p_s1->name, "Jenny");
```
### Q26. Change the age of the student to 20, using p_s
```c
    p_s1->age = 20;
```
### Q27. Create a function that takes in a pointer to a student and changes the name to "Jenny"
```c
    void change_name(student *p_s) {
        strcpy(p_s->name, "Jenny");
    }
```
### Q28. Create a function that takes in a pointer to a student and changes the age to 20
```c
    void change_age(student *p_s) {
        p_s->age = 20;
    }
```
### Q29. Call the function from Q27 in order to change the name of the student to "Jenny". Use p_s but not s
```c
    change_name(p_s1);
```
### Q30. Call the function from Q28 in order to change the age of the student to 20. Use s but not p_s
```c
    change_age(&s1);
```
### Q31. Create an array of 5 student objects
```c
    student s_arr[5];
```
### Q32. Use the functions from Q27 and Q28 on the element at index 2 of the array
```c
    change_name(s_arr+2);
    change_age(s_arr+2);
```
### Q33. Create a malloc-allocated block of memory that can store 5 students. Store the address in the variable p_block_s
```c
    student *p_block_s = (student *)malloc(sizeof(student) * 5);
```
### Q34. Make a function that takes in a pointer to an address of student, and sets that pointer to point to a new address where a student can be stored
```c
    void change_address(student **p_p_s) {
        *p_p_s = (student *)malloc(sizeof(student))
    }
```
### Q35. Call the function from Q34 in order to change the value of p_block_s to point to a new address
```c
    change_address(&p_block_s);
```
### Q36. Call the function from Q27 in order to change the name of the student at index 2 of the block of memory from Q33. Use p_block_s
```c
    change_name(p_block_s+2);
```
### Q37. Create a variable p_p_s to store the address of p_block_s
```c
    student **p_p_s = &p_block_s;
```
### Q38. Without calling any function except strcpy, and using only p_p_s, change the name of the student at index 2 to "Jennifer"
```c
    strcpy((*p_p_s + 2)->name, "Jennifer");
```
### Q39. In the name of the second student in the block pointed to by p_p_s, change the first letter to 'j'. Propose four valid to do that with one line that don't involve calling a function
```c
    ((*p_p_s + 2)->name)[0] = 'j';
```
### Q40. Write a function that takes in a pointer to the first element of a block of addresses of students, and changes the name of the student at index 2 to "Jenny"
```c
    void change_name2(student **p_p_s) {
        strcpy(p_p_s[2]->name, "Jenny");
    }
```
### Q41. Create a pointer to a block of 10 pointers to students, and store it in the variable p_block_addr_s
```c
    student **p_block_addr_s = (student **)malloc(sizeof(student *)*10);
```
### Q42. Call the function from Q40 in order to change the name of the student at index 2. Use p_block_addr_s
```c
    change_name2(p_block_addr_s);
```
### Q43. Write a function that takes in the first address of a student in a block of addresses of students, and changes the name of the student at index 2 to "Jenny"
```c
    void change_name3(student **p_block_addr_s) {
        strcpy(p_block_addr_s[2]->name, "Jenny");
    }
```
### Q44. Call the function from Q43 in order to change the name of the student at index 2. Use p_block_addr_s
```c
    change_name3(p_block_addr_s);
```