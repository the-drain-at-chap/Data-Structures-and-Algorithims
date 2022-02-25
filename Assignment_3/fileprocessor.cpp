/*  This file establishes the process of each function of the FileProcessor class. The default constructor
    and destructor do not have anything in them as no variables of the object have to be changed. No overloaded
    constructor is needed either.
*/
#include "FileProcessor.h"
#include "Translator.h"
#include "Model.h"
#include <fstream>
#include <iostream>
using namespace std;

FileProcessor::FileProcessor(){
}

FileProcessor::~FileProcessor(){
};

/*
Function name: processFile
What it does: Takes the name of the input file, opens it and takes the English sentences in the file and translates
              them to Tutnese. These translations are then put into an output file, whose name is given, and the
              translations are stored there.
@param: string inputName, string outputName
@return: none
*/
void FileProcessor::processFile(string inputName, string outputName){
  Translator someTranslator;
  ifstream inputfile;
  inputfile.open(inputName);
  ofstream outputfile;
  outputfile.open(outputName, ios_base::app);
  string input = "";
  while (!inputfile.fail()){
    getline(inputfile, input);
    input = someTranslator.translateEnglishSentence(input);
    outputfile << input << endl;
    input = "";
  }
  inputfile.close();
  outputfile.close();
}
