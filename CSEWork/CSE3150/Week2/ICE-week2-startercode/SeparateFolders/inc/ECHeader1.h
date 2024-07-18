#ifndef HEADER_1        //need ifndef, define, and endif to make sure it does not try to make multiple copies of the header file
#define HEADER_1

// A very simple header file
// What is wrong with this header file?

// define a variable
extern int time1;       // makes sure that when accessed else where, it will know what it is, avoid defining variables in header file

// define a simple function
int foo(int x);         // only define functions in header file, do not write it out


#endif