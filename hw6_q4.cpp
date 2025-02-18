#include <iostream>
#include <cmath>
using namespace std; 

void printDivisors(int n);

int main(){
  int num;
  cout << "Please enter a positive integer >=2: ";
  cin >> num;
  printDivisors(num);
  return 0;
}

void printDivisors(int n){
  for (int i = 1; i <= sqrt(n); i++){
    if (n % i == 0){
        cout << i << " ";
    }
  }
  for (int i = sqrt(n); i >= 1; i--){
    if (n % i == 0 && i != n / i){
        cout << n / i << " ";
    }
  }
}
