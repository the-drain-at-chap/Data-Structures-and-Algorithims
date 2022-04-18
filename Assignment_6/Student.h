/* This file is used to declare the Student class. It declares the public varibles, default constructor, overloaded constructor,
   destructor, and public variables needed for the Student class to work. It stores the waiting time of a student, arriving time,
   and time at the window.
*/
#include <iostream>
using namespace std;

class Student{
public:
  Student();
  Student(int aT, int tT);
  ~Student();
  int waitingTime;
  int arrivingTime;
  int timeAtWindow;
};
