#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);
const int size = 10;

int main(){
  int arr[size];  
  cout << "Please enter a list of 10 integers separated by a space: " << endl;
  for (int i = 0; i < size; i++){
    cin >> arr[i];
  }
  cout << "The minimum value is: " << minInArray(arr, size);
  return 0;
}

int minInArray(int arr[], int arrSize){
  int min = arr[0];
  for (int i = 1; i < arrSize; i++){
    if (arr[i] < min){
      min = arr[i];
    }
  }
  return min;
}
