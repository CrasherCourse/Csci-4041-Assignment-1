//
// SortAlgs.c
// Author: CrasherCourse
//

// *************************************************
// Includes
// *************************************************

#include "SortAlgs.h"
#include "FileManager.h"

// *************************************************
// Code
// *************************************************

// -------------------------------------------------
// Prototypes
// -------------------------------------------------
int compare(int a, int b);


// -------------------------------------------------
// Insertion Sort
// -------------------------------------------------
void i_sort(struct Array A)
{
    int i, j, k, temp;
    for(i = 1; i < A.size; i++)
    {
        k = i;
        for(j = k-1; j > -1; j--)
        {
            if(compare(*(A.p+j), *(A.p+k)))         //check
            {
                temp = *(A.p+j);
                *(A.p+j) = *(A.p+k);
                *(A.p+k) = temp;
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

// -------------------------------------------------
// Compare
// -------------------------------------------------
// equal to (a > b)
int compare(a, b)
{
    compCount++;
    if(a > b) return 1;
    else return 0;
}


