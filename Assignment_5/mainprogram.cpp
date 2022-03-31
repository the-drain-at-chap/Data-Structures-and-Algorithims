/* Program that takes source code file given by user in the command line and goes through the source source
   looking for delimiter errors. If there is an error program prints out the line number of the error and describes
   what kind of error it is, then program ends. */

#include "AStack.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char** argv){

  //takes source code file name from command line argument, also declares necessary variables
  ifstream sourceCode;
  string sourceCodeFileName = argv[2];
  bool thereIsError = false;
  int currentLineNumber = 1;

  //creates a Stack for each type of delimiter
  AStack<char> parenthesisStack(0);
  AStack<char> bracketStack(0);
  AStack<char> curlyBraceStack(0);

  //opens source code file, prints out error if it cannot be opened
  sourceCode.open(sourceCodeFileName);
  if(!sourceCode.is_open()){
    cout << "Could not open source code file." << endl;
  }

  //while loop used to go through each line of the source code file and look for delimiters
  while(!sourceCode.fail()){

    /* when set to true will end while loop because an error was detected, which
    will end program since only looking for one error at a time */
    bool endFile = false;

    //the contents of the current line are put into a string that will be iterated through
    string currentLine;
    getline(sourceCode, currentLine);
    for(int i = 0; i < currentLine.length(); i++){

      /* checks for ( and ) occurences, and pushes ( onto parenthesis stack when found and pops
         parenthesis stack when ) is found. If the parenthesis stack is empty when getting popped then that means
         there are more ) in source code than needed and shows error at the appropriate line.
      */
      if(currentLine[i] == '('){
        parenthesisStack.push(currentLine[i]);
      }
      if(currentLine[i] == ')'){
        if(parenthesisStack.isEmpty()){
          cout << "Error on Line " << currentLineNumber << ": extra ) found." << endl;
          endFile = true;
          thereIsError = true;
          break;
        }
        else{
          parenthesisStack.pop();
        }
      }

      /* checks for { and } occurences, and pushes { onto curly brace stack when found and pops
         curly brace stack when } is found. If the curly brace stack is empty when getting popped then that means
         there are more } in source code than needed and shows error at the appropriate line.
      */
      if(currentLine[i] == '{'){
        curlyBraceStack.push(currentLine[i]);
      }
      if(currentLine[i] == '}'){
        if(curlyBraceStack.isEmpty()){
          cout << "Error on Line " << currentLineNumber << ": extra } found." << endl;
          endFile = true;
          thereIsError = true;
          break;
        }
        else{
          curlyBraceStack.pop();
        }
      }

      /* checks for [ and ] occurences, and pushes [ onto bracket stack when found and pops
         bracket stack when ] is found. If the bracket stack is empty when getting popped then that means
         there are more ] in source code than needed and shows error at the appropriate line.
      */
      if(currentLine[i] == '['){
        bracketStack.push(currentLine[i]);
      }
      if(currentLine[i] == ']'){
        if(bracketStack.isEmpty()){
          cout << "Error on Line " << currentLineNumber << ": extra ] found." << endl;
          endFile = true;
          thereIsError = true;
          break;
        }
        else{
          bracketStack.pop();
        }
      }
    }

    /* if the parenthesis stack is not empty, then there is a missing ).
       Shows error at the appropriate line.
    */
    if(!parenthesisStack.isEmpty()){
      cout << "Error on Line " << currentLineNumber << ": expected )" << endl;
      endFile = true;
      thereIsError = true;
    }

    /* if the bracket stack is not empty, then there is a missing ].
       Shows error at the appropriate line.
    */
    else if(!bracketStack.isEmpty()){
      cout << "Error on Line " << currentLineNumber << ": expected ]" << endl;
      endFile = true;
      thereIsError = true;
    }

    //if endFile is true then breaks while loop because an error was found
    if(endFile == true){
      break;
    }

    //adds 1 to line number after going through each line of the source code
    currentLineNumber++;
  }
  sourceCode.close();

  /*Before declaring syntax to be good, checks if there is a miss } anywhere on the file.
    If not, then declares the syntax as good and asks to analyze another file. */
  if(thereIsError == false){
    if(!curlyBraceStack.isEmpty()){
      currentLineNumber++;
      cout << "Reached end of file: missing }" << endl;
      thereIsError = true;
    }
    else{
      cout << "Delimiter syntax is okay. Would you like to analyze another file?" << endl;
    }
  }

  return 0;
}
