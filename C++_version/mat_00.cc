//file: /badawika_damian/mat_00.cc
//

//Local include file
//
#include "mymatrix.h"

bool MyMatrix::read(FILE* fp) {

  //Declare a buffer and values for the rows and columns
  //
  char buf[MAX_LINE_LENGTH];
  numrows = 0;
  numcols = 0;

  //Read the file to find the number of rows
  //
  while(fgets(buf,MAX_LINE_LENGTH,fp)){
    numrows++;
  }

  //index the buffer to find the amount of columns
  //
  for(int i = 0 ; buf[i] ; i++){
    if(buf[i]==32){
      numcols++;
    }
  }
  //Print the values
  //
  printf("%d numcols, %d rows",numcols,numrows);
  
  return true;
}


bool MyMatrix::display(FILE* fp){

  //Declare variable for the number of rows, open a buffer
  //
  char buf[MAX_LINE_LENGTH];

  //Count the lines of the function
  //
  while(fgets(buf , MAX_LINE_LENGTH - 1, fp)){
    //Get rid of the null character
    //
    //buf[strlen(buf)-1] = (char)NULL;
    fprintf(stdout, "%s", buf);
    //numrows++;
  }
fprintf(stdout, "\n");
  //rewind the file pointer
  //
  rewind(fp);

/*
  //Declare variables for a vector containing each row
  //
  int* big;
  big = new int[numrows];
  float* m[numrows];
  float num;
  
   for (int i = 0; i < numrows ; i++){
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
      numcols = O;
      //Create a new float pointer for each row
      //
      m[i] = new float[O];

      //Read each line again and write the data to m until there is no more data to read
      //
      buff = buf;
      m[i][numcols] = strtof(buff, &point);
      while (point != buff) {
	      buff = point;
	      numcols++;
	      m[i][numcols] = strtof(buff , &point);
      }
    }
   fclose(fp);
   //Print the matrix
   //
   /*
    for (int k = 0; k < numrows ; k++){
      fprintf(stdout, " %d ", k);
      for(int l = 0; l < big[k]; l++) {
	      fprintf(stdout, "%10.4f ", m[k][l]);
      }
      fprintf(stdout, "\n");
    }
    */
    //memcpy(vals, m, sizeof(m)+1);

    //Clean up memory
    //
    /*
    for (int i = 0; i < strlen(buf) ; i++){
      delete [] buf[i];
    }
    */

   return true;
}


void MyMatrix::populate(FILE* fp){
  //Declare a value for the elements of the array
  //
  float N = 0;

  //float** point;
  vals = new float*[numrows];

  rewind(fp);
  //Populate each array with the values from the text file
  //
  for(int i = 0 ; i < numrows ; i++){
    //Create a float array for each row
    //
    vals[i] = new float[numcols];
    for(int j = 0 ; j < numcols ; j++){

      //Read each value from the file and write it to N
      //
      fscanf (fp, "%f", &N);
      //Insert that value into the array
      //
      *(vals[i]+j) = N;
      //vals[i][j] = point[i][j];
    }
  }
  //rewind(fp);
  fprintf(stdout, "\n");

}


bool MyMatrix::print(){
  //Index throught he whole matrix to print each element
  //
  for(int i = 0 ; i < numrows ; i++){
    for(int j = 0 ; j < numcols ; j++){
      fprintf(stdout, "[%10.4f]", vals[i][j]);
    }
    //Print a newline
    //
    fprintf(stdout, "\n");
  }
  //Print a newline
  //
  fprintf(stdout, "\n");
  return true;
}