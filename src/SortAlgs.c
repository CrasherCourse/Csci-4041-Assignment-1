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
void merge(struct Array A, int p, int q, int r);

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
                swap(A, j, k);
                k--;
            }
            else break;
        }
    }
}

// -------------------------------------------------
// Merge Sort
// -------------------------------------------------
void m_sort(struct Array A, int p, int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        m_sort(A, p, q);
        m_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

// Merge
void merge(struct Array A, int p, int q, int r)
{
    int i, j, k;
    int n = q - p + 1;
    int m = r - q;
    int L[n+1], R[m+1];
    for(i = 0; i < n; i++)
    {
        L[i] = A.p[p+i];
    }
    for(i = 0; i < m; i++)
    {
        R[i] = A.p[q+i+1];
    }
    L[n] = R[m] = INT_MAX;
    i = j = 0;
    for(k=p; k <= r; k++)
    {
        if(!compare(L[i], R[j]))
            A.p[k] = L[i++];
        else
            A.p[k] = R[j++];        
    }
}

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
        int q = partition(A, p, r);
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
            swap(A, i, j);
        }
    }
    swap(A, ++i, r);
    return i;
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


