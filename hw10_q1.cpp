#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main(){
  string sentence = "You can do it";
  int size = 0;
  string* words = createWordsArray(sentence, size);
  cout << "The input was: ";
  for (int i = 0; i < size; i++){
    cout << '"' << words[i] << '"' << " ";
  }
  cout << endl << "The size of input was: " << size; 
  return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize){
  int count = 1;
  for (int i = 0; i < sentence.length(); i++){
    if (sentence[i] == ' '){
      count++;
    }
  }
  outWordsArrSize = count;
  
  string* WordsArray = new string[count];
  int wordIndex = 0; 
  size_t startPosition = 0;
  size_t spacePosition = sentence.find(' ');

  while (spacePosition != string::npos){
    WordsArray[wordIndex] = sentence.substr(startPosition, spacePosition - startPosition);
    wordIndex++;
    startPosition = spacePosition + 1;
    spacePosition = sentence.find(' ', startPosition);
  }

  if (startPosition <= sentence.length()){
    WordsArray[wordIndex] = sentence.substr(startPosition);
  }

  return WordsArray;
}
