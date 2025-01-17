#include <iostream>
using namespace std;

int main() 
{
    double fahrenheit, celcius;

    cout << "Please enter the temperature in fahrenheit: " << endl;
    cin >> fahrenheit;
    celcius = (fahrenheit - 32) * 5.0 / 9.0;
    cout << "The temperature in celcius is: " << celcius << endl;
    return 0;

}
