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
  void addAdvisee(Student aStudent);
  void removeAdvisee(Student aStudent);
  bool hasAdvisees();
  void printInfo();

private:
  string department;
  DLList<Student>* advisees;
};
