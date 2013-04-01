//
// MySort.c
// Author: CrasherCourse
//

// *************************************************
// Includes
// *************************************************

#include "FileManager.h"

// *************************************************
// Code
// *************************************************

// Makes an int Array from a file
Array getArray(char * fname)
{
    Array x;
    FILE * fp;
    int buffer[100010];
    int e;
    x.size = 0;

    if((fp = fopen(fname, "r")) == NULL)    // Open file
    {
        perror("");
        exit(1);
    }
    
    while(fscanf(fp, "%d", &e) == 1)        // Save each int to array
    {
        buffer[x.size] = e;
        x.size++;
    }
    
    x.p = &buffer[0];                       // Save location of Array head
    return x;
}

// Save an Array to the specified file name
void saveArray (char * fname, Array A)
{
    FILE * fp;
    int i;    

    if((fp = fopen(fname, "w")) == NULL)    // Open file
    {
        perror("");
        exit(1);
    }

    for(i = 0; i < A.size; i++)
    {
        fprintf(fp, "%d\n", *(A.p+i));
    }
}

// Print out the Array A
void printArray(Array A)
{
    int i;

    for(i = 0; i < A.size; i++)
    {
        printf("%d ", *(A.p+i));
    }
    printf("\n");
}
