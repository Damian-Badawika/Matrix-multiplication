# Matrix-multiplication

This is code from HW #6 in my engineering computation I class. The assignment was to write code that would multiply 2 matrices of any dimensions from a text file. 

There are three functions in this file: read_matrix, which returns a float pointer, matcompat, which returns a boolean, and mat_mult, which returns another float pointer.

In order to be able to read and multiply matrices of any dimension, we needed to have a vector of float pointers for each row. This way the code is portable; so we call the function read_matrix once for each function, which indexes through the function and creates this vector. Then matcompat checks if they are compatible, and if they are, mat_mult multiplies them and prints the resultant matrix. Did this code actually work? No, I didn't get a very good grade on the assignment and it is still a work in progress.
