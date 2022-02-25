/*  This file declares the Model class, which is used to translate single characters from English to Tutnese.
    The default constructor and destructor are declared here. The private variables of the class are all string variables
    of each English letter, and they store that English letter's translation in Tutnese. Two methods, translateSingleCharacter
    and translateDoubleCharacter are declared here as well.
*/
#include <iostream>
#include <string>
using namespace std;

class Model{
  public:
    Model();
    ~Model();
    string translateSingleCharacter(char input);
    string translateDoubleCharacter(char input);
  private:
    string b = "bub";
    string c = "cash";
    string d = "dud";
    string f = "fuf";
    string g = "gug";
    string h = "hash";
    string j = "jay";
    string k = "kuck";
    string l = "lul";
    string m = "mum";
    string n = "nun";
    string p = "pub";
    string q = "quack";
    string r = "rug";
    string s = "sus";
    string t = "tut";
    string v = "vuv";
    string w = "wack";
    string x = "ex";
    string y = "yub";
    string z = "zub";
    string doublevowel = "squat";
    string doubleconsonant = "squa";
};
