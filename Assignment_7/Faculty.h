#include <iostream>
#include "DLList.h"
#include "Student.h"
using namespace std;

class Faculty : public Human{
public:
  Faculty();
  Faculty(int theID);
  Faculty(int theID, string theName, string theLevel, string theDepartment);
  ~Faculty();
  string getDepartment();
  void setDepartment(string theDepartment);
  void addAdvisee(int a);
  void removeAdvisee(int a);
  bool hasAdvisees();
  void printInfo();
  void setAdvisees(DLList<int> *a);
  DLList<int>* getAdvisees();

private:
  string department;
  DLList<int>* advisees;

friend bool operator==(Faculty faculty1, Faculty faculty2){
  return (faculty1.getID() == faculty2.getID());
}

friend bool operator!=(Faculty faculty1, Faculty faculty2){
  return (faculty1.getID() != faculty2.getID());
}

friend bool operator<(Faculty faculty1, Faculty faculty2){
  return (faculty1.getID() < faculty2.getID());
}

friend bool operator>(Faculty faculty1, Faculty faculty2){
  return (faculty1.getID() > faculty2.getID());
}

};
