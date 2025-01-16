#include <iostream>
using namespace std;

int main(){
    char inputChar; 
    int asciivalue;

    cout << "Please enter a character: " << endl;
    cin >> inputChar; 

    asciivalue = (int)inputChar;
    /* implicit cast */

    cout << "The ascii value of " << inputChar << " is " << asciivalue << endl;

    return 0;
}