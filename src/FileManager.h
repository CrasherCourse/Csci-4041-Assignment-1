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

#define MAX_ARRAY_SIZE 100010

typedef struct Array
{
    int size;
    int* p;
}Array;

Array getArray(char * fname);
void saveArray (char * fname, Array A);
void printArray(Array A);

#endif
