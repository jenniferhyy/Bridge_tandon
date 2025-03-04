#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main(){
  string word;
  cout << "Please enter a word: ";
  cin >> word;
  if (isPalindrome(word)){
    cout << word << " is a palindrome" << endl;
  } else {
    cout << word << " is not a palindrome" << endl;
  }
  return 0;
}

bool isPalindrome(string str){
  for (int i = 0; i < str.length(); i++){
    for (int j = str.length()-1; j >= 0; j--){
      if (str[i] != str[j]){
        return false;
      } else {
        return true;
      }
    }
  }
}
