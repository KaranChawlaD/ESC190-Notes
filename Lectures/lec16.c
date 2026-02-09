// ArrayList (homogenous)
// resizable
// a sequence of integers
// want to be able to append an integer, 
//                    insert an integer at a specific index, 
//                    delete an integet at a specific index,
//                    get the integer at specific index


#include "lec16.h"

int main() {
    int arr[] = {6, 7};
    ArrayList *L = create_list(arr, 2);
    append_list(L, 8); // L is now {6, 7, 8}
    insert_list(L, 0, 12); // L is now {12, 6, 7, 8}
    print_list(L); // prints the contents of L 

    destroy_list(L);
}