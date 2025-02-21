/* Write a function to check whether positive integer is palindrome or not */

#include <iostream>
using namespace std;

void ispalindrome(int n);

int main(){
  int num;
  cout << "Please enter a positive integer:" << endl;
  cin >> num;
  ispalindrome(num);
  return 0;
}

void ispalindrome(int n){
  int remainder = 0;
  int original = n; 
  int reversed = 0;
  while (n > 0){
    remainder = n % 10;
    reversed = reversed * 10 + remainder;
    n = n / 10;
  }
  if (original == remainder){
    cout << "This is a palindrome.";
  } else {
    cout << "This is not a palindrome.";
  }
}
