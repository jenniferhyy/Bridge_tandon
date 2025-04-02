#include <iostream>
using namespace std;

int sumofdigs(int n){
    if (n < 10){
      return n; 
    } else {
      int temp;
      temp = sumofdigs(n/10);
      return (n % 10) + temp;
    }
}

int sumofarr(int arr[], int size){
  if (size == 1){
    return arr[0];
  }  else {
    int temp; 
    temp = sumofarr(arr, size-1);
    return arr[size-1] + temp;
  }
}

int factoral(int n){
  if (n == 1){
    return n; 
  }  else {
    int temp;
    temp = factoral(n-1);
    return n * temp;
  }
}

int pow(int a, int n){
  if (n == 1){
    return a;
  } else if (n % 2 == 0){
    int temp;
    temp = pow(a, n/2);
    return temp * temp;
  } else if (n % 2 == 1){
    int temp;
    temp = pow(a, (n-1)/2);
    return a * temp * temp;
  }
}

int main(){
  cout << sumofdigs(123);
  int array[] = {1, 2, 3, 4, 5};
  int arraysize = 5;
  cout << sumofarr(array, arraysize);
  cout << factoral(5);
  return 0;
}
