#include <iostream>
using namespace std;

int main()
{
    double quarter, dime, nickel, penny, total; 
    int dollars, cents;

    cout << "Please enter number of coins:" << endl;
    cout << "# of quarters: "; 
    cin >> quarter;
    cout << "# of dimes: "; 
    cin >> dime;
    cout << "# of nickels: "; 
    cin >> nickel;
    cout << "# of pennies: "; 
    cin >> penny;

    total = quarter * 0.25 + dime * 0.10 + nickel * 0.05 + penny * 0.01;
    dollars = (int) total;
    cents = (total - (int) total) * 100;

    cout << "The total is " << dollars << " dollars and " << cents << " cents" << endl;

    return 0;
}
