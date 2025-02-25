/* computing average of student's grades */
#include <iostream>
using namespace std;

int main(){
    const int max = 60;
    int students, grades;
    double average;
    int list[max];
    int sum = 0;
    int ind;
  
    cout << "Please enter the number of students in the class (no more than "<<max<<"): " << endl;
    cin >> students;
    
    cout << "Enter the students' grades: " << endl;
    for (ind = 0; ind < students; ind++){
        cin >> grades;
        list[ind] = grades;
    }
    
    for (ind = 0; ind < students; ind++){
        sum += list[ind];
    }
    average = (double)sum / (double)students;
    
    cout << "The class average is " << average << endl;

    cout << "The grades above the average are: ";
    for (ind = 0; ind < students; ind++){
        if (list[ind] > average){
            cout << list[ind] << " ";
        }
    }
    cout << endl;
    return 0;
}
