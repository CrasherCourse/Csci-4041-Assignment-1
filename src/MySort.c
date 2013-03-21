//
// MySort.c
// Author: CrasherCourse
//

// *************************************************
// Includes
// *************************************************

#include <stdio.h>
#include "SortAlgs.h"
#include "FileManager.h"

// *************************************************
// Code
// *************************************************

int main(int argc, char **argv)
{
    struct Array A;

    A = getArray("test.txt");

    // Testing a function
/*    printf("I do q sort at the moment!\n");
    printf("Before: ");
    printArray(A);

    q_sort(A, 0, A.size - 1);  
  
    printf("After: ");
    printArray(A);
    printf("Compares: %d\n", compCount);
    saveArray("test.txt.saved", A);
*/
    merge(A, 0, A.size/2, A.size - 1);
}

