//
// SortAlgs.c
// Author: CrasherCourse
//

// *************************************************
// Includes
// *************************************************

#include <stdio.h>
#include "SortAlgs.h"

// *************************************************
// Code
// *************************************************

// -------------------------------------------------
// Prototypes
// -------------------------------------------------
int* file_to_array(void);
int* compare(int a, int b);

// -------------------------------------------------
// Insertion Sort
// -------------------------------------------------
void i_sort(int *A, int size)
{
    int i, j, k, temp;
    for(i = 1; i < (size - 1); i++)
    {
        k = i;
        for(j = k-1; j > -1; j--)
        {
            if(*(A+j) > *(A+k))         //check
            {
                temp = *(A+j);
                *(A+j) = *(A+k);
                *(A+k) = temp;
                k--;
            }
            else break;
        }
    }

}
// -------------------------------------------------
// Merge Sort
// -------------------------------------------------

// -------------------------------------------------
// Heap Sort
// -------------------------------------------------

// -------------------------------------------------
// Quick Sort
// -------------------------------------------------

