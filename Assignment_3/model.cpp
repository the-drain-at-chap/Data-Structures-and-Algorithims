/*  This file actually establishes the process of each function of the Model class. The default constructor
    and destructor do not have anything in them as no variables of the object have to be changed. No overloaded
    constructor is needed either.
*/
#include "Model.h"
#include <iostream>
#include <string>
using namespace std;

Model::Model(){
}

Model::~Model(){
};

/*
Function name: translateSingleCharacter
What it does: translates a single English character to Tutnese using a switch statement, maintains capitalization
@param: char input
@return: string translation
*/
string Model::translateSingleCharacter(char input){
  string translation = "";
  switch(input){
      case 'b':
        translation = b;
        break;
      case 'c':
        translation = c;
        break;
      case 'd':
        translation = d;
        break;
      case 'f':
        translation = f;
        break;
      case 'g':
        translation = g;
        break;
      case 'h':
        translation = h;
        break;
      case 'k':
        translation = k;
        break;
      case 'l':
        translation = l;
        break;
      case 'm':
        translation = m;
        break;
      case 'n':
        translation = n;
        break;
      case 'p':
        translation = p;
        break;
      case 'q':
        translation = q;
        break;
      case 'r':
        translation = r;
        break;
      case 's':
        translation = s;
        break;
      case 't':
        translation = t;
        break;
      case 'v':
        translation = v;
        break;
      case 'w':
        translation = w;
        break;
      case 'x':
        translation = x;
        break;
      case 'y':
        translation = y;
        break;
      case 'z':
        translation = z;
        break;
      case 'B':
        translation = b;
        translation[0] = toupper(translation[0]);
        break;
      case 'C':
        translation = c;
        translation[0] = toupper(translation[0]);
        break;
      case 'D':
        translation = d;
        translation[0] = toupper(translation[0]);
        break;
      case 'F':
        translation = f;
        translation[0] = toupper(translation[0]);
        break;
      case 'G':
        translation = g;
        translation[0] = toupper(translation[0]);
        break;
      case 'H':
        translation = h;
        translation[0] = toupper(translation[0]);
        break;
      case 'J':
        translation = j;
        translation[0] = toupper(translation[0]);
        break;
      case 'K':
        translation = k;
        translation[0] = toupper(translation[0]);
        break;
      case 'L':
        translation = l;
        translation[0] = toupper(translation[0]);
        break;
      case 'M':
        translation = m;
        translation[0] = toupper(translation[0]);
        break;
      case 'N':
        translation = n;
        translation[0] = toupper(translation[0]);
        break;
      case 'P':
        translation = p;
        translation[0] = toupper(translation[0]);
        break;
      case 'Q':
        translation = q;
        translation[0] = toupper(translation[0]);
        break;
      case 'R':
        translation = r;
        translation[0] = toupper(translation[0]);
        break;
      case 'S':
        translation = s;
        translation[0] = toupper(translation[0]);
        break;
      case 'T':
        translation = t;
        translation[0] = toupper(translation[0]);
        break;
      case 'V':
        translation = v;
        translation[0] = toupper(translation[0]);
        break;
      case 'W':
        translation = w;
        translation[0] = toupper(translation[0]);
        break;
      case 'X':
        translation = x;
        translation[0] = toupper(translation[0]);
        break;
      case 'Y':
        translation = y;
        translation[0] = toupper(translation[0]);
        break;
      case 'Z':
        translation = z;
        translation[0] = toupper(translation[0]);
        break;
      default:
        translation = translation + input;
        break;
  }
  return translation;
}

/*
Function name: translateDoubleCharacter
What it does: If a word has two letters that are the same back to back, then translates the English letters to the special
              Tutnese translation of either squa or squat.
@param: char input
@return: string translation
*/
string Model::translateDoubleCharacter(char input){
  string translation = "";
  if(isupper(input)){
    switch(input){
      case 'B':
        translation = doubleconsonant + b;
        translation[0] = toupper(translation[0]);
        break;
      case 'C':
        translation = doubleconsonant + c;
        translation[0] = toupper(translation[0]);
        break;
      case 'D':
        translation = doubleconsonant + d;
        translation[0] = toupper(translation[0]);
        break;
      case 'F':
        translation = doubleconsonant + f;
        translation[0] = toupper(translation[0]);
        break;
      case 'G':
        translation = doubleconsonant + g;
        translation[0] = toupper(translation[0]);
        break;
      case 'H':
        translation = doubleconsonant + h;
        translation[0] = toupper(translation[0]);
        break;
      case 'J':
        translation = doubleconsonant + j;
        translation[0] = toupper(translation[0]);
        break;
      case 'K':
        translation = doubleconsonant + k;
        translation[0] = toupper(translation[0]);
        break;
      case 'L':
        translation = doubleconsonant + l;
        translation[0] = toupper(translation[0]);
        break;
      case 'M':
        translation = doubleconsonant + m;
        translation[0] = toupper(translation[0]);
        break;
      case 'N':
        translation = doubleconsonant + n;
        translation[0] = toupper(translation[0]);
        break;
      case 'P':
        translation = doubleconsonant + p;
        translation[0] = toupper(translation[0]);
        break;
      case 'Q':
        translation = doubleconsonant + q;
        translation[0] = toupper(translation[0]);
        break;
      case 'R':
        translation = doubleconsonant + r;
        translation[0] = toupper(translation[0]);
        break;
      case 'S':
        translation = doubleconsonant + s;
        translation[0] = toupper(translation[0]);
        break;
      case 'T':
        translation = doubleconsonant + t;
        translation[0] = toupper(translation[0]);
        break;
      case 'V':
        translation = doubleconsonant + v;
        translation[0] = toupper(translation[0]);
        break;
      case 'W':
        translation = doubleconsonant + w;
        translation[0] = toupper(translation[0]);
        break;
      case 'X':
        translation = doubleconsonant + x;
        translation[0] = toupper(translation[0]);
        break;
      case 'Y':
        translation = doubleconsonant + y;
        translation[0] = toupper(translation[0]);
        break;
      case 'Z':
        translation = doubleconsonant + z;
        translation[0] = toupper(translation[0]);
        break;
      default:
        translation = doublevowel + input;
        translation[0] = toupper(translation[0]);
        translation[translation.size() - 1] = tolower(translation[translation.size() - 1]);
      break;
    }
  }
  else{
      switch(input){
          case 'b':
            translation = doubleconsonant + b;
            break;
          case 'c':
            translation = doubleconsonant + c;
            break;
          case 'd':
            translation = doubleconsonant + d;
            break;
          case 'f':
            translation = doubleconsonant + f;
            break;
          case 'g':
            translation = doubleconsonant + g;
            break;
          case 'h':
            translation = doubleconsonant + h;
            break;
          case 'k':
            translation = doubleconsonant + k;
            break;
          case 'l':
            translation = doubleconsonant + l;
            break;
          case 'm':
            translation = doubleconsonant + m;
            break;
          case 'n':
            translation = doubleconsonant + n;
            break;
          case 'p':
            translation = doubleconsonant + p;
            break;
          case 'q':
            translation = doubleconsonant + q;
            break;
          case 'r':
            translation = doubleconsonant + r;
            break;
          case 's':
            translation = doubleconsonant + s;
            break;
          case 't':
            translation = doubleconsonant + t;
            break;
          case 'v':
            translation = doubleconsonant + v;
            break;
          case 'w':
            translation = doubleconsonant + w;
            break;
          case 'x':
            translation = doubleconsonant + x;
            break;
          case 'y':
            translation = doubleconsonant + y;
            break;
          case 'z':
            translation = doubleconsonant + z;
            break;
          default:
            translation = doublevowel + input;
            break;
    }
  }
  return translation;
}
