#include <iostream>
#include <vector>
using namespace std;

void grades(const vector<int>& id, const vector<int>& grades);

int main(){
  
  cout << "Please enter a non-empty sequence of lines." << endl; 
  cout << "Each line should have a student ID and their grade (0-100)," << endl; 
  cout << "separated by a space." << endl << "To indicate the end of the input, enter -1 as a student ID:" <<endl;
  
  vector<int> id; 
  vector<int> grade;
  int count = 0; 
  while (true){
    int tempId, tempGrade;
    cin >> tempId;
    if (tempId == -1){
      break;
    } else {
      id.push_back(tempId);
      cin >> tempGrade;
      grade.push_back(tempGrade); 
      count++;
    }
  }
  grades(id, grade);
  return 0;
}

void grades(const vector<int>& id, const vector<int>& grades){

  int max = grades[0];
  for (int i = 0; i < grades.size(); i++){
    if (grades[i] > max){
      max = grades[i];
    }
  }
  cout << "The highest grade is " << max << endl; 

  cout << "The students with grade " << max << " are: ";
  for (int i = 0; i < grades.size(); i++){
    if (grades[i] == max){
      cout << id[i] << ' ';
    }
  }
} 
