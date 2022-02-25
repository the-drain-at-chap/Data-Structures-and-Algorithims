/* This file is used to declare the FileProcessor class, which is used to take input from an input file
   and then translate the English in that file to Tutnese. That translation is then put into an output file.
   One method, processFile, is declared here. No private variables are necessary for this class.
*/
#include <iostream>
#include <string>
using namespace std;

class FileProcessor{
  public:
    FileProcessor();
    ~FileProcessor();
    void processFile(string inputName, string outputName);
  private:

};
