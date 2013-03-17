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
    printf("I do i sort at the moment!\n");
    printf("Before: ");
    printArray(A);

    i_sort(A);  
  
    printf("After: ");
    printArray(A);
    printf("Compares: %d\n", compCount);
    saveArray("test.txt.saved", A);
}

