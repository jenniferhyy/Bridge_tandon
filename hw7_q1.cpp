#include <iostream>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
bool calLeapYear(int year);
void printYearCalendar(int year, int startingDay);
int getFebDays(int year);

int main() {
    int start, inputYear;
    cout << "Please enter a year and the starting day of the year, separated by a space: " << endl;
    cin >> inputYear >> start;
    printYearCalendar(inputYear, start);
    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {
    cout << "Mon  Tue  Wed  Thu  Fri  Sat  Sun" << endl;
    for (int i = 0; i < startingDay - 1; i++) {
        cout << "     ";
    }
    for (int k = 1; k <= numOfDays; k++) {
        if (k < 10) {
            cout << k << "    ";
        } else {
            cout << k << "   ";
        }
        if ((k + startingDay - 1) % 7 == 0 && k != numOfDays) {
            cout << endl;
        }
    }
    cout << endl;
    return ((numOfDays + startingDay - 1) % 7);
}

bool calLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int getFebDays(int year){
  if (calLeapYear(year)){
    return 29;
  } else {
    return 28;
  }
}

void printYearCalendar(int year, int startingDay){
  cout << "January " << year << endl;
  startingDay = printMonthCalender(31, startingDay) + 1;
  cout << endl;

  cout << "February " << year << endl;
  startingDay = printMonthCalender(getFebDays(year), startingDay) + 1;
  cout << endl;  
  
  cout << "March " << year << endl;
  startingDay = printMonthCalender(31, startingDay) + 1;
  cout << endl;
  
  cout << "April " << year << endl;
  startingDay = printMonthCalender(30, startingDay) + 1;
  cout << endl;

  cout << "May " << year << endl;
  startingDay = printMonthCalender(31, startingDay) + 1;
  cout << endl;
  
  cout << "June " << year << endl;
  startingDay = printMonthCalender(30, startingDay) + 1;
  cout << endl;
  
  cout << "July " << year << endl;
  startingDay = printMonthCalender(31, startingDay) + 1;
  cout << endl;
  
  cout << "August " << year << endl;
  startingDay = printMonthCalender(30, startingDay) + 1;
  cout << endl;

  cout << "September " << year << endl;
  startingDay = printMonthCalender(31, startingDay) + 1;
  cout << endl;
  
  cout << "October " << year << endl;
  startingDay = printMonthCalender(30, startingDay) + 1;
  cout << endl;

  cout << "November " << year << endl;
  startingDay = printMonthCalender(31, startingDay) + 1;
  cout << endl;
  
  cout << "December " << year << endl;
  startingDay = printMonthCalender(30, startingDay) + 1;
  cout << endl;
}
