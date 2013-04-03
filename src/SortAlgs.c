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
void swap(Array A, int a, int b);
void merge(Array A, int p, int q, int r);
void build_max_heap(Array A);
void max_heapify(Array A, int x, int size);
int parent_index(int x);
long int child_index(int x, char which);

// -------------------------------------------------
// Insertion Sort
// -------------------------------------------------
void i_sort(Array A)
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
void m_sort(Array A, int p, int r)
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
void merge(Array A, int p, int q, int r)
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
// Heap Sort
void h_sort(Array A)
{
	int i;
	int size = A.size;
	build_max_heap(A);
	for(i = (A.size - 1); i > 0; i--)
	{
		swap(A, 0, i);
		max_heapify(A, 0, --size);
	}
}
// Build Max Heap
void build_max_heap(Array A)
{
	int i;
	for(i = A.size-1; i >= 0; i--)
	{
		max_heapify(A, i, A.size);
	}
}
// Some Other max_heapify
void max_heapify(Array A, int x, int size)
{
	
	if(child_index(x, 'r') < size && compare(A.p[child_index(x, 'r')], A.p[child_index(x, 'l')]) && compare(A.p[child_index(x, 'r')], A.p[x]))	// If right child is greater than parent
	{
		swap(A, x, child_index(x, 'r'));
		max_heapify(A, child_index(x, 'r'), size);
	}
	else if (child_index(x, 'l') < size && compare(A.p[child_index(x, 'l')], A.p[child_index(x, 'r')]) && compare(A.p[child_index(x, 'l')], A.p[x]))	// If left child is greater than parent
	{
		swap(A, x, child_index(x, 'l'));
		max_heapify(A, child_index(x, 'l'), size);
	}
}

// Parent index
// Returns index of parent
int parent_index(int x)
{
	return (x-1)/2;
}
// Child index
long int child_index(int x, char which)
{
	switch(which)
	{
		case 'l':
		return (x*2 + 1);
		case 'r':
		return (x*2 + 2);
		return -1;
	}
}
// -------------------------------------------------
// Quick Sort
// -------------------------------------------------
// Quick Sort
// p = index of first element, r = last element index (p.size - 1)
void q_sort(Array A, int p, int r)
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
int partition(Array A, int p, int r)
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
void swap(Array A, int a, int b)
{
    int temp = A.p[a];
    A.p[a] = A.p[b];
    A.p[b] = temp;
}


