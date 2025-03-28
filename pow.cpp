#include <iostream>
using namespace std;

int powR(int a, int n){
  if (n == 1){
    return a;
  } else {
    int temp;
    temp = powR(a, n-1);
    return a * temp;
  }
}

int main(){
  cout << powR(10, 4);
  return 0;
}
