#include <iostream>
using namespace std;
/*
• numOfDays - The number of days in the month
• startingDay – a number 1-7 that represents the day in the week of the first day
in that month (1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.).

• Print a formatted monthly calendar of that month
• Return a number 1-7 that represents the day in the week of the last day in that
month.
*/
int printMonthCalender(int numOfDays, int startingDay, int& lastDay);

int main(){
  int num, start, L;
  cout << "Please enter the number of days in a month," << endl;
  cout << "then a number 1-7 that represents the day in" << endl;
  cout << "the week of the first day in that month (1 for" << endl;
  cout << "Monday, 2 for Tuesday, 3 for Wednesday, etc.), " << endl;
  cout << "separated by a space: " << endl;
  cin >> num >> start;
  printMonthCalender(num, start, L);
  cout << L;
  return 0;
}

int printMonthCalender(int numOfDays, int startingDay, int& lastDay){
    cout << "Mon Tue Wed Thur Fri Sat Sun" << endl;
    for (int i = 0; i < startingDay; i++){
        cout << "   ";
    }
    for (int k = 1; k <= numOfDays; k++){
        if (k < 10 ) {
            cout << " " << k << "  ";
        } else {
            cout << k << "  ";
        }
        if ((k + startingDay - 1) % 7 == 0 && k != numOfDays){
            cout << endl;
        }
    }
    cout << endl;
    int Last = (numOfDays + startingDay - 1) % 7;
    lastDay = Last;
}

