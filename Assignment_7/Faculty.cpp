#include "Faculty.h"
using namespace std;

Faculty::Faculty() : Human(){
  department = "";
  advisees = new DLList<int>();
}

Faculty::Faculty(int theID) : Human(theID, "", "") {
  department = "";
  advisees = new DLList<int>();
}

Faculty::Faculty(int theID, string theName, string theLevel, string theDepartment) : Human(theID, theName, theLevel){
  department = theDepartment;
  advisees = new DLList<int>();
}

Faculty::~Faculty(){};

string Faculty::getDepartment(){
  return department;
}

void Faculty::setDepartment(string s){
  department = s;
}

bool Faculty::hasAdvisees(){
  if(advisees->isEmpty()){
    return true;
  }
  return false;
}

void Faculty::addAdvisee(int a){
  advisees->insertBack(a);
}

void Faculty::setAdvisees(DLList<int> *a){
  advisees = a;
}

DLList<int>* Faculty::getAdvisees(){
  return advisees;
}

/*
void Faculty::removeAdvisee(Student aStudent){
  advisees->remove(aStudent); //haven't implemented in DLList.h yet
} */

void Faculty::printInfo(){
  cout << "Faculty ID: " << getID() << endl;
  cout << "Name: " << getName() << endl;
  cout << "Level: " << getLevel() << endl;
  cout << "Department: " << department << endl;
  cout << "Advisees: ";
  if(advisees->length() == 0){
    cout << "0" << endl;
  }
  else{
    for(int i = 0; i < advisees->length(); i++){
      cout << advisees->findItem(i) << " ";
    }
    cout << endl;
  }
}
