#include "Faculty.h"
using namespace std;

Faculty::Faculty() : Human(){
  department = "";
  advisees = new DLList<Student>();
}

Faculty::Faculty(int theID) : Human(theID, "", "") {
  department = "";
  advisees = new DLList<Student>();
}

Faculty::Faculty(int theID, string theName, string theLevel, string theDepartment) : Human(theID, theName, theLevel){
  department = theDepartment;
  advisees = new DLList<Student>();
}

Faculty::~Faculty(){};

string Faculty::getDepartment(){
  return department;
}

bool Faculty::hasAdvisees(){
  if(advisees->isEmpty()){
    return true;
  }
  return false;
}

void Faculty::addAdvisee(Student aStudent){
  advisees->insertBack(aStudent);
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
  cout << "Advisees: " << endl;
}
