// file: /badawika_damian/mymath.cc
//

//Local include file
//
#include "mymatrix.h"

int main(int argc, char** argv) {

  //Index through the command line and set all values to lowercase so the input is case insensitive
  //
  for(int i = 0 ; i < argc ; i++){
    for(int j = 0 ; j < strlen(argv[i]) ; j++){
      // arglower[i][j] = tolower(argv[i][j]);
      argv[i][j] = tolower(argv[i][j]);
    }
  }

  //Declare an integer for the number of files
  //
  int files = argc - 3;
  //Declare an array of MyMatrix objects, 1 for each file
  //
  MyMatrix mat[files];

  //Index the command line for each file
  //
  for(int i = 0 ; i < files ; i++){
    //Open each file
    //
    mat[i].fp = fopen(argv[argc-i-1],"r");

    //Error handling for invalid file
    //
    if(mat[i].fp == NULL){
      fprintf(stderr, "File open error\n");
      return 1;
    }
    //mat[i].display(mat[i].fp);
    //Read the values from each file
    //
    mat[i].read(mat[i].fp);
    //Populate the array with all the values
    //
    mat[i].populate(mat[i].fp);
    }

  //Index the command line for a help command or operation
  //
  for(int i = 1 ; i < argc ; i++) {
    if(strcmp(argv[i], "help") == 0) {
      //Display the help file
      //
      system("more help.txt");
      return 1;
    }
    //Look for the operation option
    //
    if(strcmp(argv[i], "-operation") == 0) {
      //Compute and print the matrix operations for each operation
      //
      if(strcmp(argv[i + 1], "addition") == 0) {
	      MyMatrix result = mat[0] + mat[1];
        //Print the first matrix
        //
        mat[0].print();
        //Print the second
        //
        mat[1].print();
        //Print the result
        //
        result.print();
      }
      else if(strcmp(argv[i + 1], "subtraction") == 0) {
	      MyMatrix result = mat[0] - mat[1];
        //Print the first matrix
        //
        mat[0].print();
        //Print the second
        //
        mat[1].print();
        //Print the result
        //
        result.print();
      }
      else if(strcmp(argv[i + 1], "multiplication") == 0) {
	      MyMatrix result = mat[0] * mat[1];
        //Print the first matrix
        //
        mat[0].print();
        //Print the second
        //
        mat[1].print();

        //Print the result
        //
        result.print();
      }

      //Print an error message if no operation is specified
      //
      else {
	      fprintf(stderr, "No operation specified");
	      return 1;
       }
     }
  }

  //Exit gracefully
  //
  return 0;
}
