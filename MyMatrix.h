// file: p01/p01.h
//
// this is a simple template for an include file

// make sure definitions are only made once
//
#ifndef ISIP_EXAMPLE
#define ISIP_EXAMPLE

// system include files
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// define my favorite number
//
#define JOES_NUMBER (float)27.0
//Define max line length for an array
//
#define MAX_LINE_LENGTH 9999

// define a function
//
float** read_matrix(FILE* fp, int* &big);
bool matcompat(int x1 , int x2 , int *y1 , int *y2);
float** mat_mult(float** a, float** b, int x1 , int x2 , int *y1 , int *y2);

// end of include file
//
#endif
