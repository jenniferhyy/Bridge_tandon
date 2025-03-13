#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main(){
  int arr[] = {5, 2, 11, 7, 6, 4};
  int arrSize = 6;
  oddsKeepEvensFlip(arr, arrSize);
  return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize){
  
  // figuring out number of odds and even numbers
  int oddCount = 0; 
  int evenCount = 0; 
  for (int i = 0; i < arrSize; i++){
    if (arr[i]%2 == 1){
      oddCount++;
    } else {
      evenCount++;
    }
  }
  
  // putting all odd and even numbers into 2 separate arrays
  int* ArrOdd = new int[oddCount];
  int* ArrEven = new int[evenCount];
  int oddIndex = 0;
  int evenIndex = 0;
  for (int i = 0; i < arrSize; i++){
    if (arr[i]%2 == 1){
      ArrOdd[oddIndex] = arr[i];
      oddIndex++;
    } else {
      ArrEven[evenIndex] = arr[i];
      evenIndex++;
    }
  }

  // arranging even numbers in reversed order
  int* ArrEvenArranged = new int[evenCount];
  evenIndex = 0;
  for (int i = evenCount-1; i >= 0; i--){
      ArrEvenArranged[evenIndex] = ArrEven[i];
      evenIndex++;
    }
  
  // organising numbers in combined array
  int* arrCombined = new int[arrSize];
  int oddIndex1 = 0;
  int evenIndex1 = 0; 
  for (int i = 0; i < oddCount; i++){
    arrCombined[i] = ArrOdd[oddIndex1];
    oddIndex1++;
  }
  for (int i = oddCount; i < arrSize; i++){
    arrCombined[i] = ArrEvenArranged[evenIndex1];
    evenIndex1++;
  }
  for (int i = 0; i < arrSize; i++){
    cout << arrCombined[i] << " ";
  }

  // clean up dynamically allocated memory; 
  delete[] ArrOdd;
  delete[] ArrEven;
  delete[] ArrEvenArranged;
  delete[] arrCombined;

}
