#include <iostream>
using namespace std;

int sumArrayR(int arr[], int arrsize){
  if (arrsize == 1){
    return arr[0];
  } else {
    int temp = sumArrayR(arr, arrsize-1);
    return temp + arr[arrsize-1];
  }
}

int main(){
  int input[] = {10, 2, -6, 9, 11, 3};
  int size = 6;
  cout << sumArrayR(input, size);
  return 0;
}
