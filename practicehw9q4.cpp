#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main(){
  int arr[] = {3, -1, -3, 0, 6, 4};
  int arrSize = 6;
  int outSize;
  
  // Implementation 1
  int* output1 = getPosNums1(arr, arrSize, outSize);
  cout << "(a) ";
  for (int i = 0; i < outSize; i++){
    cout << output1[i] << " ";
  }
  delete[] output1;

  // Implementation 2
  int* output2 = getPosNums2(arr, arrSize, &outSize);
  cout << "(b) ";
  for (int i = 0; i < outSize; i++){
    cout << output2[i] << " ";
  }
  delete[] output2;

  // Implementation 3
  int* output3;
  getPosNums3(arr, arrSize, output3, outSize);
  cout << "(c) ";
  for (int i = 0; i < outSize; i++){
    cout << output3[i] << " ";
  }
  delete[] output3;

  // Implementation 4
  int* output4 = nullptr;
  getPosNums4(arr, arrSize, &output4, &outSize);
  cout << "(d) ";
  for (int i = 0; i < outSize; i++){
    cout << output4[i] << " ";
  }
  delete[] output4;
  return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
  int countPos = 0;
  for (int i = 0; i < arrSize; i++){
    if (arr[i] > 0){
      countPos++;
    }
  }
  int* PosArr = new int[countPos];
  int PosArrIndex = 0;
  for (int i = 0; i < arrSize; i++){
    if (arr[i] > 0){
      PosArr[PosArrIndex] = arr[i];
      PosArrIndex++;
    }
  }
  outPosArrSize = countPos;
  return PosArr; 
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
  int countPos = 0;
  for (int i = 0; i < arrSize; i++){
    if (arr[i] > 0){
      countPos++;
    }
  }
  int* posArr = new int[countPos];
  int PosArrIndex = 0;
  for (int i = 0; i < arrSize; i++){
    if (arr[i] > 0){
      posArr[PosArrIndex] = arr[i];
      PosArrIndex++;
    }
  }
  *outPosArrSizePtr = countPos;
  return posArr;
}
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
  int countPos = 0;
  for (int i = 0; i < arrSize; i++){
    if (arr[i] > 0){
      countPos++;
    }
  }
  int PosArrIndex = 0;
  outPosArr = new int[countPos];
  for (int i = 0; i < arrSize; i++){
    if (arr[i] > 0){
      outPosArr[PosArrIndex] = arr[i];
      PosArrIndex++;
    }
  }
  outPosArrSize = countPos; 
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
  int countPos = 0; 
  for (int i = 0; i < arrSize; i++){
    if (arr[i] > 0){
      countPos++;
    }
  }
  int PosArrIndex = 0;
  int* outPosArr = new int[countPos];
  for (int i = 0; i < arrSize; i++){
    if (arr[i] > 0){
      outPosArr[PosArrIndex] = arr[i];
      PosArrIndex++;
    }
  }
  *outPosArrPtr = outPosArr;
  *outPosArrSizePtr = countPos;
}
