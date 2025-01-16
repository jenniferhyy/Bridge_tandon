#include <iostream>
using namespace std; 

int main()

{
    char lowercase, uppercase; 
    int offset; 
    
    cout << "Please enter enter a lower case letter " << endl;
    cin >> lowercase;

    offset = (int)(lowercase - 'a');
    uppercase = (char)('A' + offset);

    cout << "Uppercase of " << lowercase << " is " << uppercase <<endl;
    return 0;
}
