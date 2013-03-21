//
// SortAlgs.c
// Author: CrasherCourse
//

// =================================================
// Includes
// =================================================

#include "SortAlgs.h"
#include "FileManager.h"

// =================================================
// Code
// =================================================

// -------------------------------------------------
// Prototypes
// -------------------------------------------------
int compare(int a, int b);
void swap(struct Array A, int a, int b);

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
            if(compare(A.p[j], A.p[k]))         //check
            {
                temp = A.p[j];                    // Move A[j] up
                A.p[j] = A.p[k];
                A.p[k] = temp;
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
// Quick Sort
// p = index of first element, r = last element index (p.size - 1)
void q_sort(struct Array A, int p, int r)
{
    if(p < r)
    {
        int q = partition(A, q, r);
        q_sort(A, p, q-1);
        q_sort(A, q+1, r);
    }
}

// Partition
// returns index of pivot element
int partition(struct Array A, int p, int r)
{
    int pivot = A.p[r];     // Assign last element as pivot
    int i = p-1;
    int j;

    for(j = p; j < r; j++)
    {
        if(!compare(A.p[j], pivot))  //!(a > b) == a <= b
        {
            i++;    
        }
    }
}


// -------------------------------------------------
// Other
// -------------------------------------------------
// compare
// Increments compCount, returns (a > b)
int compare(a, b)
{
    compCount++;
    return (a > b);
}
// swap: swaps elements A.p[a] and A.p[b]
void swap(struct Array A, int a, int b)
{
    int temp = A.p[a];
    A.p[a] = A.p[b];
    A.p[b] = temp;
}


