#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    double radius, area;
    cout << "Please enter the radius: " << endl;
    cin >> radius;
    area = radius * radius * M_PI; 
    cout << "The area of a circle with radius " << radius << " is " << area << endl;

}

/* if want to convert expression from int to double: 

int x1, x2;
double y1, y2;

y1 = 6 (double);
x1 = 6.7 (int); --> removes fractional part

if want to mix types: 

int x; 
double y; 

cout << 5.0 / 2 << endl;
x would be 2,
y would also be 2 

*/

