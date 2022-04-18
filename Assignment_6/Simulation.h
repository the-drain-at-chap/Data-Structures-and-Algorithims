/* This file is used to declare the Simulation class which is used to actually simulate the assignment. The
   default constructor, destructor, functions, and public and private varibles are declared here. It has all the needed
   key parts that the assignement asks for like the metrics and the actual simulation.
*/
#include "Student.h"
#include "Window.h"
#include "DLLQueue.h"
#include <iostream>
#include <fstream>
using namespace std;

class Simulation {
public:
  Simulation(string inputFileName);
  ~Simulation();
  int time;
  void simulate();
  void calculateMetrics();
  void displayMetrics();

public:
  DLLQueue<Student*>* arrivingQueue;
  DLLQueue<Student*>* waitingLine;
  DLLQueue<Window*>* openWindows;
  DLLQueue<Student*>* finishedStudents;
  DLLQueue<Student*>* occupiedStudents;
  DLLQueue<Window*>* occupiedWindows;
  double meanStudentWait = 0;
  int medianStudentWait = 0;
  int longestStudentWait = 0;
  int numStudentsOverTen = 0;
  double meanWindowIdle = 0;
  int longestWindowIdle = 0;
  int numWindowsOverFive = 0;
};
