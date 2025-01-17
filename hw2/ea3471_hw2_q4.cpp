#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num1, num2, sum, subtract, product, remainder, divQuotient;
    double quotient;
    cout << "Please enter two positive integers, separated by a space:\n";
    cin >> num1 >> num2;
    sum = num1 + num2;
    subtract = num1 - num2;
    product = num1 * num2;
    divQuotient = num1 / num2;
    quotient = (double) num1 / num2;
    remainder = num1 % num2;
    cout << num1 << " + " << num2 << " = " << sum << "\n";
    cout << num1 << " - " << num2 << " = " << subtract << "\n";
    cout << num1 << " * " << num2 << " = " << product << "\n";
    cout << num1 << " / " << num2 << " = " << quotient << "\n";
    cout << num1 << " div " << num2 << " = " << divQuotient << "\n";
    cout << num1 << " mod " << num2 << " = " << remainder << "\n";
    return 0;
}
