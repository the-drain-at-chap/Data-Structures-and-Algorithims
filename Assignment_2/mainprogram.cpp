#include "Parser.h"
using namespace std;

int main(){
  string userInput;
  cout << "Enter a string: " << endl;
  getline(cin, userInput);                        //gets string user wants to input and puts it into userInput variable
  Parser testParser(userInput);                   //creates Parser object with the string being userInput
  testParser.ParseString();                       //successfully parses through userInput string to get number of alphabets and nonalphabets
  testParser.CreateOutputFile();                  //prints results to an output.txt file
  return 0;
}
