#include <iostream>
using namespace std;

#define ARR_SIZE 10

int main(){
  double sum;
  double arr[ARR_SIZE];
  for(int i = 0; i < ARR_SIZE; ++i){
    cout << "Enter price: " << endl;
    cin >> arr[i];
    if(arr[i] < 0){
      break;
    }
  }
  for(int i = 0; i < ARR_SIZE; ++i){
    sum = sum + arr[i];
  }
  cout << "The total cost is: " << sum << endl;
  return 0;
}
