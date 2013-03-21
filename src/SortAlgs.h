//
// SortAlgs.h
// Author: CrasherCourse
//
#ifndef SORTALGS_H
#define SORTALGS_H

#include <stdio.h>
#include "FileManager.h"

#define INT_MAX 2147483647 

int compCount;

void i_sort(struct Array A);
void m_sort(struct Array A, int p, int r);
void h_sort(struct Array A);
void q_sort(struct Array A, int p, int r);

#endif
