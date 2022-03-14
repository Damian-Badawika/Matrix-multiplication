// file: /hw_06/matrix_multiply
//

//Local include files
//
#include "MyMatrix.h"

int main(int argc, char** argv){
  //Declare variables
  //
  FILE* fp = fopen(argv[1],"r");
  FILE* fp2 = fopen(argv[2], "r");
  int x1 = atoi(argv[3]);
  int x2 = atoi(argv[4]);
  int* y1;
  int* y2;

  //Error handling for missing files
  //
  if (fp == NULL){
    fprintf(stdout, "File open error, unable to open file pointer\n");
    return 1;
  }
  else if (fp2 == NULL){
    fprintf(stdout, "File open error, unable to open file pointer 2\n");
    return 1;
    }

  //Error handling for insufficient arguments
  //
  if (argc != 5){
    fprintf(stdout, "Not enough arguments stupid\n");
    return 1;
  }

  //Call function to read matrices and write them to 2 float pointers
  //
  float** a = read_matrix(fp, y1);
  float** b = read_matrix(fp2, y2);

  //If the matricesa aren't compatible, print an error message
  //
  if (matcompat(x1 , x2 , y1 , y2)==false){
    fprintf(stdout,"These matrices can't be multiplied dummy");
  }
  //If they are compatible, call the multiplication function
  //
  else{
  fprintf(stdout,"Multiplication result\n");
  mat_mult(a , b , x1 , x2 , y1 , y2);
  }

  //Exit really smoothly and well
  //
  return 0;
}
