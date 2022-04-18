/* Implements the constructors and destructor of the Student class.
*/
#include "Student.h"

Student::Student(){
  arrivingTime = 0;
  timeAtWindow = 0;
  waitingTime = 0;
}


Student::Student(int aTime, int tTime){
  arrivingTime = aTime;
  timeAtWindow = tTime;
  waitingTime = 0;
}

Student::~Student(){};
