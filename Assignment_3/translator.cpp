/*  This file establishes the process of each function of the Translator class. The default constructor
    and destructor do not have anything in them as no variables of the object have to be changed. No overloaded
    constructor is needed either.
*/
#include "Translator.h"
#include "Model.h"
#include <iostream>
using namespace std;

Translator::Translator(){
}

Translator::~Translator(){
};

/*
Function name: translateEnglishWord
What it does: translates a whole English word to Tutnese
@param: string input
@return: string translatedWord
*/
string Translator::translateEnglishWord(string input){
  Model someModel;
  string translatedWord = "";
  for (int i = 0; i < input.size(); i++){
    if(input[i] == input[i + 1]){
      translatedWord = translatedWord + someModel.translateDoubleCharacter(input[i]);
      i += 1;
    }
    else{
      translatedWord = translatedWord + someModel.translateSingleCharacter(input[i]);
    }
  }
  return translatedWord;
}

/*
Function name: translateEnglishSentence
What it does: translates an entire English sentence to Tutnese.
@param: string input
@return: string translatedSentence
*/
string Translator::translateEnglishSentence(string input){
  string translatedSentence;
  string word;
  for(int i = 0; i < input.size(); i++){
    if(!isalpha(input[i])){
      translatedSentence = translatedSentence + translateEnglishWord(word);
      translatedSentence = translatedSentence + input[i];
      word = "";
    }
    else if(i == input.size() - 1){
      word = word + input[i];
      translatedSentence = translatedSentence + translateEnglishWord(word);
    }
    else{
      word = word + input[i];
    }
  }
  return translatedSentence;
}
