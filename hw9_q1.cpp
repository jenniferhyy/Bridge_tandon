#include <iostream>
#include <string>
using namespace std;

int NumOfWords(string line);

int main(){
  string currLine;
  cout << "Please enter a line of text: " << endl;
  getline(cin, currLine);
  cout << NumOfWords(currLine) << "  words" << endl;
  return 0;
}

int NumOfWords(string line){
  int count = 0;
  for (int i = 0; i < line.length(); i++){
    if (line[i] == " " || line[i] == "."|| line[i] == ","){
      count++;
    }
  }
  return count;
}

void Alphabets(string line){
  for (int i = 0; i < line.length(); i++){
    if (line[i] == )
  }
}
