//
// MySort.c
// Author: CrasherCourse
//

// *************************************************
// Includes
// *************************************************

#include "FileManager.h"
#include "SortAlgs.h"

// *************************************************
// Code
// *************************************************

// Makes an int Array from a file
struct Array getArray(char * fname)
{
    struct Array x;
    FILE * fp;
    int buffer[100010];
    int e;
    x.size = 0;

    if((fp = fopen(fname, "r")) == NULL)
    {
        perror("");
        exit(1);
    }
    
    while(fscanf(fp, "%d", &e) == 1)
    {
        buffer[x.size] = e;
        x.size++;
    }
    
    x.p = &buffer[0];
    return x;
}

// Print out the Array A
void printArray(struct Array A)
{
    int i;

    for(i = 0; i < A.size; i++)
    {
        printf("%d ", *(A.p+i));
    }
    printf("\n");
}
