#include "Student.h"
#include <string>
using namespace std;

Student::Student() : Human(){
  major = "";
  gpa = 0.0;
  advisor = 0;
}

Student::Student(int theID) : Human(theID, "", ""){
  major = "";
  gpa = 0;
  advisor = 0;
}

Student::Student(int theID, string theName, string theLevel, string theMajor, double theGPA, int theAdvisor) : Human(theID, theName, theLevel){
  major = theMajor;
  gpa = theGPA;
  advisor = theAdvisor;
}

Student::~Student(){};

string Student::getMajor(){
  return major;
}

double Student::getGPA(){
  return gpa;
}

int Student::getAdvisor(){
  return advisor;
}

void Student::setMajor(string theMajor){
  major = theMajor;
}

void Student::setGPA(double theGPA){
  gpa = theGPA;
}

void Student::setAdvisor(int theAdvisor){
  advisor = theAdvisor;
}

string Student::printInfo(){
  cout << "Student ID: " << getID() << endl;
  cout << "Name : " << getName() << endl;
  cout << "Level: " << getLevel() << endl;
  cout << "Major: " << major << endl;
  cout << "GPA: " << gpa << endl;
  cout << "Advisor: " << advisor << endl;
}
