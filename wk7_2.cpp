#include <iostream>
#include <string>
using namespace std; 

int main(){
  string str;
  string name;
  int ind;
  cout >> "Please enter your name: " << endl;
  getline(cin, str);
  cout << str << endl;

  // indexing 
  string str1, str2; 
  char ch; 
  str1 = "abcdefg";
  cout << str1[0];
  ch = str1[3];

  // slicing strings - prints "de"
  cout << str1.substr(3,2) << endl;

  //str.length() - number of char in the string

  // print backwards

  cout << "Please enter you name: " << endl;
  getline(cin, name);
  for (ind = name.length()-1; ind > 0; ind--){
    cout << name[ind];
  }

  // comparing strings 
  string word1, word2, word3;
  cout << "Please enter 3 words separated by a space: " << endl;
  cin >> word1 >> word2 >> word3;
  if (word1 <= word2 && word1 <= word3){
    cout << word1 << endl;
  } if (word2 <= word1 && word2 <= word3){
    cout << word2 << endl;
  } else {
    cout << word3 << endl;
  }

  //searching: str.find(s)
  string str5 = "abcdcdefg";
  cout << str.find("de") << endl; // output is the index
  if (str.find("xyz") == string::npos){
    cout << "Not found" << endl;
  } else {
    cout << "Found" << endl;
  }
  cout << str.find("cd") // there are 2 "cd" in the string = output is the first occurrence
  cout << str.find("cd", 4) // searches after position 4 in the index
  return 0;
}
