//
// MySort.c
// Author: CrasherCourse
//

// *************************************************
// Includes
// *************************************************

#include "FileManager.h"
#include <time.h>

// *************************************************
// Code
// *************************************************

// Makes an int Array from a file
Array getArray(char * fname)
{
    Array x;
    FILE * fp;
    //int buffer[100010];						// Hard max size is 10010
    int e;
    x.size = 0;
	x.p = malloc(100010*sizeof(int)); 
	
    if((fp = fopen(fname, "r")) == NULL)    // Open file
    {
        perror("");
        exit(1);
    }
    
    while(fscanf(fp, "%d", &e) == 1)        // Save each int to array
    {
        x.p[x.size] = e;
        x.size++;
    }
    
    //x.p = &buffer[0];                       // Save location of Array head
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
    
    fprintf(fp, "%ld compares\n", compCount);
    fprintf(fp, "%ld milliseconds\n", sortTime);
    fclose(fp);
    
    if(!isSorted(A))  printf("%s sort did not sort %s correctly\n", sortAlg, fname);
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
	clock_gettime(CLOCK_MONOTONIC, &t1);
}

// Stop the timer
void stopTimer(void)
{
	clock_gettime(CLOCK_MONOTONIC, &t2);
	sortTime = (t2.tv_sec - t1.tv_sec)*1000;
	sortTime += (t2.tv_nsec - t1.tv_nsec)/1000000;
}

// Is sorted
int isSorted(Array A)
{
	int i, j;
	if(A.size < 1) return 1;
	
	for(i = 0, j = 1; j < A.size; i++, j++)
	{
		if(A.p[i] > A.p[j]) return 0;
	}
	return 1;
}


