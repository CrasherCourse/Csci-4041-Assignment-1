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
    Array A;
    
	if(argc != 3)
	{
		printf("Usage: %s [i|m|h|q] [filename]\n", argv[0]);
		return 1;
	}
	
	
    A = getArray(argv[2]);

    // Testing a function
    
    if(!strcmp(argv[1], "i"))			// I sort
    {
		startTimer();
		i_sort(A);
		stopTimer();
		saveArray(argv[2], "i", A);
	}
	else if(!strcmp(argv[1], "m"))
    {
		startTimer();
		m_sort(A, 0, A.size-1);
		stopTimer();
		saveArray(argv[2], "m", A);
	}
	else if(!strcmp(argv[1], "h"))
    {
		startTimer();
		h_sort(A);
		stopTimer();
		saveArray(argv[2], "h", A);
	}
	else if(!strcmp(argv[1], "q"))
    {
		startTimer();
		q_sort(A, 0, A.size-1);
		stopTimer();
		saveArray(argv[2], "q", A);
	}
	else   								// Nonvalid sort argument
	{
		printf("Nonvalid sorting argument: %s\n", argv[1]);
		exit(1);
	}
    

}

