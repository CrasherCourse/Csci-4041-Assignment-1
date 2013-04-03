//
// SortAlgs.h
// Author: CrasherCourse
//
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100010

unsigned long int compCount, sortTime;
struct timespec t1, t2;


typedef struct Array
{
    int size;
    int* p;
}Array;

Array getArray(char * fname);
void saveArray (char * fname, char * sortAlg, Array A);
void printArray(Array A);
void startTimer(void);
void stopTimer(void);

#endif
