// file: /lab_11/badawika_damian/mymatrix.h
//

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
#include <ctype.h>


static long MAX_LINE_LENGTH = 99999;
// define a simple class
//
class MyMatrix {

public:

  //MyMatrix();
  bool read(FILE* fp);
  bool display(FILE* fp);
  void populate(FILE* fp);
  bool print();

  int numrows;
  int numcols;
  FILE* fp;
  
  // define protected data
  //
protected:
  
  // define some data
  //
  float** vals;
  //int numrows;
  //int numcols;

public:

//Overloading the + operator
//
MyMatrix operator + (MyMatrix arg) {
  //Declare a result mymatrix
  //
  MyMatrix sum;

  //Error handling
  //
  if(numrows != arg.numrows){
    fprintf(stderr, "ERROR: Matrices not compatible");
    exit(-1);
  }
  //Float pointer
  //
  sum.vals = new float*[numrows];

  for(int i = 0 ; i < numrows ; i++){
    //Float array for each row
    //
    sum.vals[i] = new float[numcols];
    for(int j = 0 ; j < numcols ; j++){
      //Compute the sum of all values
      //
      sum.vals[i][j] = vals[i][j] + arg.vals[i][j];
    }
  }

  //Size values for the result array
  //
  sum.numrows = numrows;
  sum.numcols = arg.numcols;

  //return the result
  //
  return sum;
}

//Overloading the - operator
//
MyMatrix operator - (MyMatrix arg) {
  //Declare a result mymatrix
  //
  MyMatrix sum;

  //Error handling
  //
  if(numrows != arg.numrows){
    fprintf(stderr, "ERROR: Matrices not compatible");
    exit(-1);
  }

  //Float pointer for each row
  //
  sum.vals = new float*[numrows];

  for(int i = 0 ; i < numrows ; i++){
    sum.vals[i] = new float[numcols];
    for(int j = 0 ; j < numcols ; j++){
      //Compute the difference of the 2 arrays
      //
      sum.vals[i][j] = vals[i][j] - arg.vals[i][j];
    }
  }

  //Size values for the result array
  //
  sum.numrows = numrows;
  sum.numcols = arg.numcols;

  //return a result
  //
  return sum;
}

//Overloading the * operator
//
MyMatrix operator * (MyMatrix arg) {
  //Declare a value for the result
  //
  MyMatrix sum;

  //Error handling for incompatible matrices
  //
  if(numrows != arg.numrows){
    fprintf(stderr, "ERROR: Matrices not compatible");
    exit(-1);
  }
  //Declare float pointers for each row
  //
  sum.vals = new float*[numrows];

  for(int i = 0 ; i < numrows ; i++){
    //Delcare a float array for each row
    //
    sum.vals[i] = new float[numcols];
    for(int k = 0 ; k < numrows ; k++){
      for(int j = 0 ; j < numcols ; j++){
        //compute the product of the 2 arrays
        //
        sum.vals[i][k] += vals[i][j] * arg.vals[j][k];
    }
    }
  }

  //Declare size values for the result array
  //
  sum.numrows = numrows;
  sum.numcols = arg.numcols;

  //return the result
  //
  return sum;
}

};

#endif