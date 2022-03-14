// file: lecture_18/example.cc
//
// generate a sinewave to a file
//

// include files
//
#include "example.h"

// main program
//
int main(int argc, char** argv) {

  // open a file
  //
  FILE* fp = fopen(argv[1], "r");
  if (fp == (FILE*)NULL) {
    fprintf(stdout, "**> error opening file\n");
    return(-1);
  }

  // read the file line by line to get the number of rows
  //
  char buf[MAX_LINE_LENGTH];
  long nrows = 0;
  fprintf(stdout, "file contains:\n");

  while (fgets(buf, MAX_LINE_LENGTH - 1, fp)) {

    // strip the newline character
    //
    buf[strlen(buf)-1] = (char)NULL;

    // echo the line
    //
    fprintf(stdout, " line no. %d: %s\n", nrows, buf);

    // increment the line counter
    //
    nrows++;
  }
    
  // rewind the file
  //
  rewind(fp);

  // declare a vector to hold the matrix and its dimensions
  //
  long sizes[nrows];
  float* m[nrows];
  float val;

  // read the file line by line to get the data
  //
  for (long i = 0; i < nrows; i++) {

    // read a line and strip the newline character
    //
    fgets(buf, MAX_LINE_LENGTH - 1, fp);
    buf[strlen(buf)-1] = (char)NULL;

    // count the number of items on the line using the C function strtof():
    //  read the next item. if there are no more items to read, strtof
    //  will not advance the pointer. we read, advance the pointer, read
    //  again... using a while loop.
    //
    char* ptr = NULL;
    char* pbuf = buf;
    long ncols = 0;

    strtof(pbuf, &ptr);
    while (ptr != pbuf) {
      ncols++;
      pbuf = ptr;
      strtof(pbuf, &ptr);
    }
    
    // save the number of cols
    //
    sizes[i] = ncols;

    // create space for the row of data
    //
    m[i] = new float[ncols];

    // reparse the line and set values:
    //  use strtof() again and read, advance the pointer, read, etc., until
    //  there is no more data to read.
    //
    pbuf = buf;
    long j = 0;
    m[i][j] = strtof(pbuf, &ptr);
    while (ptr != pbuf) {
      pbuf = ptr;
      j++;
      m[i][j] = strtof(pbuf, &ptr);
    }
  }

  // close the file
  //
  fclose(fp);

  // print the matrix
  //
  fprintf(stdout, "matrix values:\n");
  for (long i = 0; i < nrows; i++) {
    fprintf(stdout, " %d: ", i);
    for (long j = 0; j < sizes[i]; j++) {
      fprintf(stdout, "%10.4f ", m[i][j]);
    }
    fprintf(stdout, "\n");
  }

  // clean up memory
  //
  for (long i = 0; i < nrows; i++) {
    delete [] m[i];
  }

  // exit gracefully
  //
  return 0;
}

