#include "Human.h"
using namespace std;

Human::Human(){
  id = 0;
  name = "";
  level = "";
}

Human::Human(int theID, string theName, string theLevel){
  id = theID;
  name = theName;
  level = theLevel;
}

Human::~Human(){};

int Human::getID(){
  return id;
}

string Human::getName(){
  return name;
}

string Human::getLevel(){
  return level;
}

void Human::setID(int theID){
  id = theID;
}

void Human::setName(string theName){
  name = theName;
}

void Human::setLevel(string theLevel){
  level = theLevel;
}
