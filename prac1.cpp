#include <iostream>
using namespace std;

int fib(int n);
void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main(){

// HW6(1) fibonacci sequence
  int num;
  cout << "Please enter a positive integer: ";
  cin >> num;
  cout << int fib(num);
  cout << endl;

// HW6(2) pinetree1 
  prinShiftedTriangle(3, 4, '+');

// HW6(2) pinetree2
  printPineTree(3, `#`);

  return 0;

}

// HW6(1) fibonacci sequence
int fib(int n){
  int a;
  int b = 1;
  int c = 1; 
  if (n == 1 || n == 2){
    return 1;
  } else {
    for (int i = 3; i <= n; i++){
      a = b + c; // a = 1+2 // a = 3+2 // a = 5+3
      b = a;     // b = 3  // b = 5    // b = 8
      c = b;     // c = 2  // c = 3    // c = 5
    }
    return a;
  }
}

/* HW6(2) pinetree 
[][][][][][]+        | line 0, 6 spaces, 1 symbol
[][][][][]+ + +      | line 1, 5 spaces, 3 symbols
[][][][] + + + + +   | line 2, 4 spaces, 5 symbols
*/
void printShiftedTriangle(int n, int m, char symbol){
  for (int i = 0; i < n; i++{
    for (int k = 0; k < m + n - i; k++){
      cout << ' ';
    }
    for (int j = 0; j < 2*(i+1)-1; j++){
      cout << symbol;
    }
    cout << endl;
  }
}

/* HW6(2) pinetree2 (3, #)
[][][]#     | rep 1, line 0, 3 space, 1 #
[][]###     | rep 1, line 1, 2 space, 3 #

[][][]#     | rep 2, line 0, 3 space, 1 #
[][]###     | rep 2, line 1, 2 space, 3 #
[]#####     | rep 2, line 2, 1 space, 5 #

[][][]#     | rep 3, line 0, 3 space, 1 #
[][]###     | rep 3, line 1, 2 space, 3 #
[]#####     | rep 3, line 2, 1 space, 5 #
#######     | rep 3, line 3, 0 space, 7 #
*/
void printPineTree(int n, char symbol){
  for (int i = 0; i < n; i++){
    for (int k = 0; k <= i; k++){
      for (int j = 0; j < n-k; j++){
        cout << ' ';
      } 
      for (int l = 0; l < 2*k+1; l++){
        cout << symbol;
      }
      cout << endl;
    }
  }
}

/* hw6(3) approximation of e */
double eApprox(int n){
  int factoral = 1.0;
  int sum = 1.0;
  for (int i = 1; i <= n; i++){
    factoral = factoral * i; 
    sum = 1.0 / factoral;
  }
}
