/* Implements the default constructor, destructor, and all functions that are needed to simulate through the required
   instructions of the assignment.
*/
#include "Simulation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
using namespace std;

//default constructor, analyzes through input file to create number of windows and number of students that will arrive
Simulation::Simulation(string inputFileName){
  time = 0;
  arrivingQueue = new DLLQueue<Student*>();
  waitingLine = new DLLQueue<Student*>();
  openWindows = new DLLQueue<Window*>();
  finishedStudents = new DLLQueue<Student*>();
  occupiedStudents = new DLLQueue<Student*>();
  occupiedWindows = new DLLQueue<Window*>();
  ifstream inputFile;
  inputFile.open(inputFileName);
  if(!inputFile.is_open()){
    cout << "Could not open input file." << endl;
  }
  string lineContent;
  getline(inputFile, lineContent);
  int lineContentConverted = stoi(lineContent);
  for(int i = 0; i < lineContentConverted; i++){
    openWindows->enqueue(new Window());
  }
  while(getline(inputFile, lineContent)){
    if(lineContent == ""){
      continue;
    }
    else{
      int arrivalTime = stoi(lineContent);
      getline(inputFile, lineContent);
      int numStudents = stoi(lineContent);
      for(int i = 0; i < numStudents; i++){
        getline(inputFile, lineContent);
        arrivingQueue->enqueue(new Student(arrivalTime, stoi(lineContent)));
      }
    }
  }
  inputFile.close();
}

//destructor
Simulation::~Simulation(){};

/*
Function name: simulate
What it does: runs the simulation that the assignment asks for.
@param: none
@return: none
*/
void Simulation::simulate(){
  int originalStudentNum = arrivingQueue->length();
  while(true){
    if(finishedStudents->length() == originalStudentNum){
      break;
    }
    for(int i = 0; i < arrivingQueue->length(); i++){
      Student* currentStudent = new Student();
      currentStudent = arrivingQueue->findItemInQueue(i);
      if(currentStudent->arrivingTime == time){
        waitingLine->enqueue(currentStudent);
        arrivingQueue->dequeue();
        i--;
      }
    }
    while(!waitingLine->isEmpty() && !openWindows->isEmpty()){
      Student* temporaryStudent = new Student();
      temporaryStudent = waitingLine->dequeue();
      occupiedStudents->enqueue(temporaryStudent);
      Window* temporaryWindow = new Window();
      temporaryWindow = openWindows->dequeue();
      occupiedWindows->enqueue(temporaryWindow);
    }
    for(int i = 0; i < openWindows->length(); i++){
      openWindows->findItemInQueue(i)->idleTime++;
    }
    for(int i = 0; i < waitingLine->length(); i++){
      waitingLine->findItemInQueue(i)->waitingTime++;
    }
    for(int i = 0; i < occupiedStudents->length(); i++){
      int occupiedTime = occupiedStudents->findItemInQueue(i)->timeAtWindow;
      if(occupiedTime == 0){
        Student* temporaryStudent = new Student();
        temporaryStudent = occupiedStudents->dequeue();
        finishedStudents->enqueue(temporaryStudent);
        Window* temporaryWindow = new Window();
        temporaryWindow = occupiedWindows->dequeue();
        openWindows->enqueue(temporaryWindow);
      }
      else{
        occupiedStudents->findItemInQueue(i)->timeAtWindow--;
      }
    }
    time++;
  }
  displayMetrics();
}

/*
Function name: calculateMetrics
What it does: calculates the metrics that the assignment asks for.
@param: none
@return: none
*/
void Simulation::calculateMetrics(){
  double totalWaitTime = 0;
  int counter = 0;
  longestStudentWait = finishedStudents->frontValue()->waitingTime;
  DLLQueue<Student*>* sortedWaitingTimes = new DLLQueue<Student*>();
  for(int i = 0; i < finishedStudents->length(); i++){
    totalWaitTime += finishedStudents->findItemInQueue(i)->waitingTime;
    if(finishedStudents->findItemInQueue(i)->waitingTime > longestStudentWait){
      longestStudentWait = finishedStudents->findItemInQueue(i)->waitingTime;
    }
    if(finishedStudents->findItemInQueue(i)->waitingTime > 10){
      numStudentsOverTen++;
    }
  }
  meanStudentWait = totalWaitTime / finishedStudents->length();
  while(finishedStudents->length() != sortedWaitingTimes->length()){
    for(int i = 0; i < finishedStudents->length(); i++){
      if(finishedStudents->findItemInQueue(i)->waitingTime == counter){
        sortedWaitingTimes->enqueue(finishedStudents->findItemInQueue(i));
      }
    }
    counter++;
  }
  if(sortedWaitingTimes->length() == 4){
    medianStudentWait = (sortedWaitingTimes->findItemInQueue(1)->waitingTime + sortedWaitingTimes->findItemInQueue(2)->waitingTime) / 2;
  }
  else if(sortedWaitingTimes->length() % 2 == 0){
    int firstIndex = sortedWaitingTimes->length() / 2;
    int secondIndex = sortedWaitingTimes->length() / 2 + 1;
    medianStudentWait = (sortedWaitingTimes->findItemInQueue(firstIndex)->waitingTime + sortedWaitingTimes->findItemInQueue(secondIndex)->waitingTime) / 2;
  }
  else{
    int medianIndex = sortedWaitingTimes->length() / 2;
    medianStudentWait = sortedWaitingTimes->findItemInQueue(medianIndex)->waitingTime;
  }
  double totalIdleTime;
  longestWindowIdle = openWindows->frontValue()->idleTime;
  for(int i = 0; i < openWindows->length(); i++){
    totalIdleTime += openWindows->findItemInQueue(i)->idleTime;
    if(openWindows->findItemInQueue(i)->idleTime > longestWindowIdle){
      longestWindowIdle = openWindows->findItemInQueue(i)->idleTime;
    }
    if(openWindows->findItemInQueue(i)->idleTime > 5){
      numWindowsOverFive++;
    }
  }
  meanWindowIdle = totalIdleTime / openWindows->length();
}

/*
Function name: displayMetrics
What it does: displays the metrics that the assignment asks for.
@param: none
@return: none
*/
void Simulation::displayMetrics(){
  calculateMetrics();
  cout << "mean student wait time in queue: " << meanStudentWait << endl;
  cout << "median student wait time in queue: " << medianStudentWait << endl;
  cout << "longest student wait time in queue: " << longestStudentWait << endl;
  cout << "no. of students waiting > 10 ticks: " << numStudentsOverTen << endl;
  cout << "mean window idle time: " << meanWindowIdle << endl;
  cout << "longest window idle time: " << longestWindowIdle << endl;
  cout << "no. of windows idle > 5 ticks: " << numWindowsOverFive << endl;
}
