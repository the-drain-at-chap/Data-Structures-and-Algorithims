#include <iostream>
#include "Human.h"
using namespace std;

class Student:public Human{
public:
  Student();
  Student(int theID);
  Student(int theID, string theName, string theLevel, string theMajor, double theGPA, int theAdvisor);
  ~Student();
  string getMajor();
  double getGPA();
  int getAdvisor();
  void setMajor(string theMajor);
  void setGPA(double theGPA);
  void setAdvisor(int theAdvisor);
  string printInfo();

private:
  string major;
  double gpa;
  int advisor;
};
