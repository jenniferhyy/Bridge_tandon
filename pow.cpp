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
int fastpow(int a, int n){
  if (n == 1){
    return a;
  } else {
    if (n % 2 == 0){
      return fastpow(a, n/2) * fastpow(a, n/2);
    } else {}
      return a * fastpow(a, (n-1)/2) * fastpow(a, (n-1)/2);
  }
}

int main(){
  cout << powR(10, 4);
  cout << fastpow(10, 4);
  return 0;
}

/* runtime for fastpow is the same as powR (i.e. theta(n))
    T(fastpow) = 1 + 2 + 4 + 8 ... + n
               = 2n-1 = n 
*/
