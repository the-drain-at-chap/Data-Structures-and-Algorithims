#include <iostream>
using namespace std;

#define ARR_SIZE 3

int main(){
  int age1;
  int age2;
  int age3;
  int youngest;
  int oldest;
  cout << "First age: " << endl;
  cin >> age1;
  cout << "Second age: " << endl;
  cin >> age2;
  cout << "Third age: " << endl;
  cin >> age3;
  int arr[ARR_SIZE] = {age1, age2, age3};
  youngest = age1;
  oldest = age1;
  for(int i = 0; i < ARR_SIZE; ++i){
    if(arr[i] > oldest){
      oldest = arr[i];
    }
    if(arr[i] < youngest){
      youngest = arr[i];
    }
  }
  cout << "Youngest age: " << youngest << endl;
  cout << "Oldest age: " << oldest << endl;
  return 0;
}
