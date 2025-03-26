#include <iostream>
using namespace std;

void printAsterisks(int k){
  if (k == 0){
    cout << endl;
    return;
  }
  cout << "*";
  printAsterisks(k-1);
}

void printTriangle(int n){
  if (n == 0){
    return;
  }  
  printTriangle(n-1);
  printAsterisks(n);
}

void printIncreasingTriangle(int j, int i){
  if (j < i){
    return;
  }  
  printAsterisks(i);
  printIncreasingTriangle(j, i+1);
}

void printDecreasingTriangle(int j, int i){
  if (j < i){
    return;
  }
  printAsterisks(j - i + 1);
  printDecreasingTriangle(j, i + 1);
}

void printOppositeTriangles(int n){
  printDecreasingTriangle(n, 1);
  printIncreasingTriangle(n, 1);
}

void printRulerRecursive(int left, int right, int dashes){
  if (left > right){
    return;
  }
  int mid = (left + right) / 2; 
  printRulerRecursive(left, mid - 1, dashes - 1);
  for (int i = 0; i < dashes; i++){
    cout << "-";
  }

}
int main(){
  printTriangle(4);
  printOppositeTriangles(4);
  return 0;
}
