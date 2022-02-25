/* This file is used to declare the Translator class, which is used to translate English words and sentences
   to Tutnese. Both default constructor and destructor are declared. Two methods, translateEnglishWord and
   translateEnglishSentence are declared here. No private variables are necessary for this class.
*/
#include <iostream>
#include <string>
using namespace std;

class Translator{
  public:
    Translator();
    ~Translator();
    string translateEnglishWord(string input);
    string translateEnglishSentence(string input);
  private:

};
