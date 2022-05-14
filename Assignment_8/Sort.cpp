/* Implementation of the constructors, destructor, and functions of the Sort class. Functions include all the sorting methods and the simulation function that runs in
   main for the program to actually work.
*/
#include "Sort.h"
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

//default constructor
Sort::Sort(){}

//destructor
Sort::~Sort(){};

/*
Function name: merge
What it does: used to complete the runMergeSort function
@param: double anArray[], int lower, int middle, int upper
@return:
*/
void Sort::merge(double anArray[], int lower, int middle, int upper){
  int i;
  int j;
  int k;
  double left[middle - lower + 1];
  double right[upper - middle];
  for(i = 0; i < middle - lower + 1; i++){
    left[i] = anArray[lower + i];
  }
  for(j = 0; j < upper - middle; j++){
    right[j] = anArray[middle + 1 + j];
  }
  i = 0;
  j = 0;
  k = lower;
  for(k = lower; i < middle - lower + 1 && j < upper - middle; k++){
    if(left[i] <= right[j]){
      anArray[k] = left[i++];
    }
    else{
      anArray[k] = right[j++];
    }
  }
  while(i < middle - lower + 1){
    anArray[k++] = left[i++];
  }
  while(j < upper - middle){
    anArray[k++] = right[j++];
  }
}

/*
Function name: runMergeSort
What it does: executes the merge sort algorithim on the unsorted array
@param: double anArray[], int lower, int upper
@return: none
*/
void Sort::runMergeSort(double anArray[], int lower, int upper){
  if(lower >= upper){
    return;
  }
  runMergeSort(anArray, lower, ((lower + upper) / 2));
  runMergeSort(anArray, ((lower + upper) / 2) + 1, upper);
  merge(anArray, lower, (lower + upper) / 2, upper);
}

/*
Function name: runBubbleSort
What it does: executes the bubble sort algorithim on the unsorted array
@param: double anArray[], int size
@return: none
*/
void Sort::runBubbleSort(double anArray[], int size){
  for(int i = 0; i < size - 1; i++){
    for(int j = 0; j < size - i - 1; j++){
      if(anArray[j] > anArray[j + 1]){
        double temp = anArray[j];
        anArray[j] = anArray[j + 1];
        anArray[j + 1] = temp;
      }
    }
  }
}

/*
Function name: runSelectionSort
What it does: executes the selection sort algorithim on the unsorted array
@param: double anArray[], int size
@return: none
*/
void Sort::runSelectionSort(double anArray[], int size){
  int i;
  int j;
  int imin;
  for(i = 0; i < size - 1; i++){
    imin = i;
    for(j = i + 1; j < size; j++){
      if(anArray[j] < anArray[imin]){
        imin = j;
      }
    }
    if(imin != i){
      double temp = anArray[i];
      anArray[i] = anArray[imin];
      anArray[imin] = temp;
    }
  }
}

/*
Function name: simulate
What it does: used to simulate the entire program that meets the assignment's requirements
@param: string s
@return: none
*/
void Sort::simulate(string s){
  ifstream inputStream;
  int length;
  inputStream.open(s);
  inputStream >> length;
  double* mergeArray = new double[length];
  double* selectionArray = new double[length];
  double* bubbleArray = new double[length];
  for(int i = 0; i < length; i++){
    inputStream >> mergeArray[i];
  }
  inputStream.close();
  for(int i = 0; i < length; i++){
    selectionArray[i] = mergeArray[i];
    bubbleArray[i] = mergeArray[i];
  }
  auto start = high_resolution_clock::now();
  runMergeSort(mergeArray, 0, length - 1);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cout << "Merge Sort" << endl;
  cout << "Start time: " << duration_cast<milliseconds>(start.time_since_epoch()).count() << endl;
  cout << "End Time: " << duration_cast<milliseconds>(stop.time_since_epoch()).count() << endl;
  cout << "Duration: " << duration.count() << " milliseconds. " <<endl;
  cout << "" << endl;

  start = high_resolution_clock::now();
  runSelectionSort(selectionArray, length);
  stop = high_resolution_clock::now();
  duration = duration_cast<milliseconds>(stop - start);
  cout << "Selection Sort" << endl;
  cout << "Start time: " << duration_cast<milliseconds>(start.time_since_epoch()).count() << endl;
  cout << "End Time: " << duration_cast<milliseconds>(stop.time_since_epoch()).count() << endl;
  cout << "Duration: " << duration.count() << " milliseconds. " <<endl;
  cout << "" << endl;

  start = high_resolution_clock::now();
  runBubbleSort(bubbleArray, length);
  stop = high_resolution_clock::now();
  duration = duration_cast<milliseconds>(stop - start);
  cout << "Bubble Sort" << endl;
  cout << "Start time: " << duration_cast<milliseconds>(start.time_since_epoch()).count() << endl;
  cout << "End Time: " << duration_cast<milliseconds>(stop.time_since_epoch()).count() << endl;
  cout << "Duration: " << duration.count() << " milliseconds. " <<endl;
  cout << "" << endl;

}
