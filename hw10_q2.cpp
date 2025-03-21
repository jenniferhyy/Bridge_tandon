#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main(){
  int array[] = {3, 1, 3, 0, 6, 4};
  int size = 6;
  int outputsize;
  int* missingarray = findMissing(array, size, outputsize);
  cout << "The missing numbers are: ";
  for (int i = 0; i < outputsize; i++){
    cout << missingarray[i] << " ";
  }
  delete[] missingarray;
  return 0;
}

int* findMissing(int arr[], int n, int& resArrSize){
  resArrSize = 0;
  bool* present = new bool[n+1]();
  for (int i = 0; i < n; i++){
    present[arr[i]] = true;
  }
  for (int i = 0; i <= n; i++){
    if (!present[i]){
      resArrSize++;
    }
  }
  int* outputarr = new int[resArrSize];
  int index = 0;
  for (int i = 0; i <= n; i++){
    if (!present[i]){
      outputarr[index++] = i;
    }
  }
  delete[] present;
  return outputarr;
}
