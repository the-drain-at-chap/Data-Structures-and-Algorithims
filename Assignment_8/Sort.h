/* Initializes the constructors, destructor, functions, and variables of the Sort class. Sort class will have the three sorting methods as functions
   and will include the simulate function to execute what the assignment wants in main.
*/
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
