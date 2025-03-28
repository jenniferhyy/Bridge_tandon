#include <iostream>
using namespace std;

int sumArrayR1(int arr[], int arrsize){
  if (arrsize == 1){
    return arr[0];
  } else {
    int temp = sumArrayR1(arr, arrsize-1);
    return temp + arr[arrsize-1];
  }
}

int sumArrayR2(int arr[], int arrsize){
  if (arrsize == 1){
    return arr[0];
  } else {
   int temp = sumArrayR2(arr+1, arrsize-1);
    return arr[0] + temp;
  }
}

int main(){
  int input[] = {10, 2, -6, 9, 11, 3};
  int size = 6;
  cout << sumArrayR1(input, size);
  cout << sumArrayR2(input, size);
  return 0;
}
