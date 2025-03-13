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
  int* outPosArr;
  getPosNums3(arr, arrSize, outPosArr, outSize);
  cout << "(c) ";
  for (int i = 0; i < outSize; i++){
    cout << outPosArr[i] << " ";
  }
  delete[] outPosArr; 

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
  int posCount = 0; 
  for (int i = 0; i < arrSize; i++){
    if (arr[i] > 0){
      posCount++;
    }
  }
  int index = 0;
  int *posArr = new int[posCount];
  for (int i = 0; i < arrSize; i++){
    if (arr[i] > 0){
      posArr[index] = arr[i];
      index++;
    }
  }
  outPosArrSize = posCount;
  return posArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
  int posCount = 0; 
  for (int i = 0; i < arrSize; i++){
    if (arr[i] > 0){
      posCount++;
    }
  }
  int index = 0;
  int *posArr = new int[posCount];
  for (int i = 0; i < arrSize; i++){
    if (arr[i] > 0){
      posArr[index] = arr[i];
      index++;
    }
  }
  *outPosArrSizePtr = posCount;
  return posArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
  int posCount = 0; 
  for (int i = 0; i < arrSize; i++){
    if (arr[i] > 0){
      posCount++;
    }
  }
  int index = 0;
  outPosArr = new int[posCount];
  for (int i = 0; i < arrSize; i++){
    if (arr[i] > 0){
      outPosArr[index] = arr[i];
      index++;
    }
  }
  outPosArrSize = posCount;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int posCount = 0; 
    for (int i = 0; i < arrSize; i++){
      if (arr[i] > 0){
        posCount++;
      }
    }
    int index = 0;
    int* outPosArr = new int[posCount];
    for (int i = 0; i < arrSize; i++){
      if (arr[i] > 0){
        outPosArr[index] = arr[i];
        index++;
      }
    }
    *outPosArrPtr = outPosArr;
    *outPosArrSizePtr = posCount;
}

