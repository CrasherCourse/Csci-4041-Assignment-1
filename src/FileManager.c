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
    int buffer[100010];						// Hard max size is 10010
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
void saveArray (char * fname, char * sortAlg, Array A)
{
    FILE * fp;
    int i;
	char sname[100];
	sprintf(sname, "%s_%s.sorted", sortAlg, fname);
	
    if((fp = fopen(sname, "w")) == NULL)    // Open .sorted file
    {
        perror("");
        exit(1);
    }

    for(i = 0; i < A.size; i++)				// Print each number to the new file
    {
        fprintf(fp, "%d\n", *(A.p+i));
    }
    
    fclose(fp);
    
    strcat(sname, ".stats");
    if((fp = fopen(sname, "w")) == NULL)    // Open .stats file
    {
        perror("");
        exit(1);
    }
    
    fprintf(fp, "%d compares\n", compCount);
    
}

// Print out the Array A, for debugging purposes
void printArray(Array A)					
{
    int i;

    for(i = 0; i < A.size; i++)
    {
        printf("%d ", *(A.p+i));
    }
    printf("\n");
}

// Start the timer and compare counter
void startTimer(void)
{
	compCount = 0;
}

// Stop the timer
void stopTimer(void)
{
}
