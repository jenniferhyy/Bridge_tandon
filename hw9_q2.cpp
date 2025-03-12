#include <iostream>
#include <string>
using namespace std;

bool LineAnalysis(string line1, string line2);

int main(){
  string input1, input2;
  cout << "Please enter the first line of text: " << endl;
  getline(cin, input1);
  cout << "Please enter the second line of text: " << endl;
  getline(cin, input2);
  if (LineAnalysis(input1, input2)){
    cout << "The phrases are anagrams" << endl; 
  } else {
    cout << "The phrases are not anagrams" << endl; 
  }
  return 0;  
}

bool LineAnalysis(string line1, string line2){
  int LetterCount1[26] = {0};
  int LetterCount2[26] = {0};
  bool isAnagram = false;

  for (int i = 0; i < line1.length(); i++){
    if (line1[i] >= 'a' && line1[i] <= 'z'){
      LetterCount1[line1[i]-'a']++;
    } else if (line1[i] >= 'A' && line1[i] <= 'Z'){
      LetterCount1[line1[i]-'A']++;
    }
  }
  
  for (int i = 0; i < line2.length(); i++){
    if (line2[i] >= 'a' && line2[i] <= 'z'){
      LetterCount2[line1[i]-'a']++;
    } else if (line2[i] >= 'A' && line2[i] <= 'Z'){
      LetterCount2[line2[i]-'A']++;
    }
  }

  for (int i = 0; i < 26; i++){
    if (line1[i] == line2[i] && LetterCount1[i] == LetterCount2[i]){
      isAnagram = true;
    } 
  }
  return isAnagram;
} 
