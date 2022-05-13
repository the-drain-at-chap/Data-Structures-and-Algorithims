#include <iostream>
using namespace std;

class Sort{
public:
  Sort();
  ~Sort();
  void merge(double anArray[], int lower, int middle, int upper);
  void runMergeSort(double anArray[], int lower, int upper);
  void runSelectionSort(double anArray[], int size);
  void runBubbleSort(double anArray[], int size);
  void simulate(string s);

private:

};
