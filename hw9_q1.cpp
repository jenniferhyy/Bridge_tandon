#include <iostream>
#include <string>
using namespace std;

int NumOfWords(string line);
void CountAlphabets(string line);

int main(){
  string currLine;
  cout << "Please enter a line of text: " << endl << flush;
  getline(cin, currLine);
  cout << NumOfWords(currLine) << "  words" << endl;
  CountAlphabets(currLine);
  return 0;
}

int NumOfWords(string line){
  int count = 0;
  bool inWord = false;
  for (int i = 0; i < line.length(); i++){
    if (line[i] == ' ' || line[i] == '.' || line[i] == ','){
      inWord = false;
    } else if (!inWord){
      inWord = true; 
      count++;
    }
  }
  return count;
}

void CountAlphabets(string line){
  int letterCount[26] = {0};
  for (int i = 0; i < line.length(); i++){
    if (line[i] >= 'A' && line[i] <= 'Z'){
      letterCount[line[i] - 'A']++;
    } else if (line[i] >= 'a' && line[i] <= 'z'){
      letterCount[line[i] - 'a']++;
    }
  }
  for (int i = 0; i < 26; i++){
    if (letterCount[i] > 0){
      cout << letterCount[i] << "  " << (char)('a' + i) << endl;
    }
  }
}
