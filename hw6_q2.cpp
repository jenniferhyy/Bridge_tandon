#include <iostream>
using namespace std; 

/* 
printShiftedTriangle(3, 4, `+`)

      +     1 (j = 1) | 6 spaces (4+3-1) / (m+n-j) | char x1 (2j-1) | 
     +++    2 (j = 2) | 5 spaces (4+3-2) / (m+n-j) | char x3 (2j-1) | 
    +++++   3 (j = 3) | 4 spaces (4+3-3) / (m+n-j) | char x5 (2j-1) |

printPineTree(3, `#`)
   #      3 space | 1 # *** 1 rep (k) | print 2 lines (j<=k+1) | line 1 = 3[] (n-j+1) | +1# | (2*j-1)
  ###     2 space | 3 #                                        | line 2 = 2[] (n-j+1) | +3# | (2*j-1)
   #      3 space | 1 # *** 2 rep (k) | print 3 lines (j=k+1) | 
  ###     2 space | 3 #
 #####    1 space | 5 # 
   #      3 space | 1 # *** 3 rep (k) | print 4 lines | 
  ###     2 space | 3 # 
 #####    1 space | 5 #
#######   0 space | 7 #  

*/

void printShiftedTriangle(int n, int m, char symbol);

void printPineTree(int n, char symbol);

int main(){
  int num1, num2, num3; 
  char character1, character2;
  cout << "Please enter 2 numbers and a symbol, separated by spaces: ";
  cin >> num1 >> num2 >> character1;
  printShiftedTriangle(num1, num2, character1);
  cout << "Please enter a number and a symbol, separated by a space: ";
  cin >> num3 >> character2;
  printPineTree(num3, character2);
  return 0; 
}

void printShiftedTriangle(int n, int m, char symbol){
  for (int j = 1; j <= n; j++) {
      for (int k = 0; k < m+n-j; k++){
        cout << " ";
      }
      for (int l = 0; l < 2*j-1; l++){
        cout << symbol;
      }
    cout << endl;
  }
}

void printPineTree(int n, char symbol){
  for (int k = 1; k <= n; k++){
    for (int j = 1; j <= k+1; j++){
      for (int l = 0; l < n-j+1; l++){
        cout << " ";
      }
      for (int p = 0; p < 2*j-1; p++) {
        cout << symbol;
      }
      cout << endl;
    }
  }
}

