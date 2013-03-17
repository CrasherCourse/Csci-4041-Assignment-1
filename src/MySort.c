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
printArray(A);
saveArray("test.txt.saved", A);

/*
    int i;
    int array[MAX_ARRAY_SIZE];
    int size = 7;
    array[0] = 10;
    array[1] = 35;
    array[2] = 17;
    array[3] = 1;
    array[4] = 29;
    array[5] = 64;
    array[6] = 42;
    compCount = 0;

    // Testing a function
    printf("I do i sort at the moment!\n");
    printf("Before: ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    i_sort(&array[0], size);  
  
    printf("After: ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Compares: %d\n", compCount);
*/
}

