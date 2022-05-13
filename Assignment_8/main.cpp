#include <iostream>
#include "Sort.h"
using namespace std;

int main(int argc, char** argv){
  string inputfile = argv[1];
  Sort aSort;
  aSort.simulate(inputfile);
  return 0;
}
