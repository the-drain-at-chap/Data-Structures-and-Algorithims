/* This file takes in the input file name from the command line and declares a Sort object, and uses the simulate function to simulate
   what the assignment is asking for.
*/
#include <iostream>
#include "Sort.h"
using namespace std;

int main(int argc, char** argv){
  string inputfile = argv[1];
  Sort aSort;
  aSort.simulate(inputfile);
  return 0;
}
