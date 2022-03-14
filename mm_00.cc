// file: /hw_06/badawika_damian/mm_00.cc
//

//Local include files
//
#include "MyMatrix.h"

float** read_matrix(FILE* fp, int* &big){
  
  //Declare variable for the number of rows, open a buffer
  //
  int N = 0;
  char buf[MAX_LINE_LENGTH];

  //Count the lines of the function
  //
  while(fgets(buf , MAX_LINE_LENGTH - 1, fp)){
    //Get rid of the null character
    //
    buf[strlen(buf)-1] = (char)NULL;
    N++;
  }

  //Rewind the file
  //
  rewind(fp);

  //Declare variables for a vector containing each row
  //
  big = new int[N];
  float* m[N];
  float num;

  //Read the file pointer and get the values
  //
    for (int i = 0; i < N ; i++){
      //Read each line and get rid of the new line character
      //
      fgets(buf , MAX_LINE_LENGTH - 1, fp);
      buf[strlen(buf)-1] = (char)NULL;

      //These while loops read each item of the matrices
      //
      char* point = NULL;
      char* buff = buf;
      long O = 0;

      strtof(buff, &point);
      while (point != buff){
	O++;
	buff = point;
	strtof(buff, &point);
      }

      big[i] = O;

      //Create a new float pointer for each row
      //
      m[i] = new float[O];

      //Read each line again and write the data to m until there is no more data to read
      //
      buff = buf;
      long j = 0;
      m[i][j] = strtof(buff, &point);
      while (point != buff) {
	buff = point;
	j++;
	m[i][j] = strtof(buff , &point);
      }
    }
    //Close the file
    //
    fclose(fp);

    //Print the matrix
    //
    for (int k = 0; k < N ; k++){
      fprintf(stdout, " %d ", k);
      for(int l = 0; l < big[k]; l++) {
	fprintf(stdout, "%10.4f ", m[k][l]);
      }
      fprintf(stdout, "\n");
    }

    //Clean up memory
    //
    for (int i = 0; i < N ; i++){
      delete [] m[i];
    }
    
    return m;
}

//Function to check if the matrices are compatible
//
bool matcompat(int x1 , int x2 , int* y1 , int* y2){
  int N = 0;

  //Check if the rows of columns in m1 is equal to the amount of rows in m2
  //
  for (int i = 0; i < *y1 ; i++) {
      if (y1[i] == x2) {
	return true;
      }
      else{
	return false;
      }
  }    
  return false;
}

//Function to multiply the 2 matrices
//
float** mat_mult(float** a, float** b, int x1 , int x2 , int *y1 , int *y2){
  //Declare a resultant matrix
  //
  float** mat3;
  //char buf[MAX_LINE_LENGTH];

  mat3 = new float*[x1];
  //Create a new float pointer for each row
  //
  for( long i = 0; i < x1 ; i++){
    mat3[i] = new float[y2[i]];
  }

  //Multiply the indeces of both matrices
  //
  for(int i = 0; i < x1 ; i++){
    fprintf(stdout,"%d: ", i);
    for(int j = 0; j < y2[i] ; j++){
      mat3[i][j] = 0;
      for(int k = 0; k < x2 ; k++){
	//Apply the matrix multiplication formula
	//
	mat3[i][j] += a[i][k] * b[k][j];
      }
      //Print the result
      //
      fprintf(stdout,"%0.2f ", mat3[i][j]);
    }
    fprintf(stdout,"\n");
  }
  return mat3;
}
