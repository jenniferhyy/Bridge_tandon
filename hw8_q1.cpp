#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);
const int size = 20;

int main(){
  int arr[size]; 
  int min;
  cout << "Please enter 20 integers separated by a space: " << endl;
  for (int i = 0; i < size; i++){
    cin >> arr[i];
  }
  min = minInArray(arr, size);
  cout << "The minimum value is: " << min;
  cout << ", and it is located in the following indices: ";
  for (int i = 0; i < size; i++){
    if (min == arr[i]){
      cout << i << " ";
    }
  }
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
