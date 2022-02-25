/* This is the main program for the assignment. It creates a FileProcessor object and then asks the user
   for the input and output file names. These are used for the processFile function, and the function is called
   in main after the user input to translate whatever is in the input file to the output file. Each class
   is utilized to accomplish this.
*/
#include "FileProcessor.h"
#include <iostream>
using namespace std;

int main(){
  FileProcessor someFileProcessor;
  string inputName;
  string outputName;
  cout << "Give input file name: " << endl;
  cin >> inputName;
  cout << "Give output file name: " << endl;
  cin >> outputName;
  someFileProcessor.processFile(inputName, outputName);
  return 0;
}
