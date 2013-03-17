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

struct Array
{
    int size;
    int* p;
};

struct Array getArray(char * fname);
void printArray(struct Array A);

#endif
