#include <iostream>
using namespace std;

int sumofdig(int n){
  if (n < 10){
    return n;
  } else {
    return (n % 10) + sumofdig(n/10);
  }
}

int main(){
  cout << sumofdig(123);
  return 0;
}
