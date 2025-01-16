#include <iostream>
using namespace std;

int main ()

{
    char ch1, ch2; 

    ch1 = 'a';
    ch2 = 'a' + 1;

    cout << ch2 << endl; // implicitly casted from int to char
    cout << 'a' + 1 << endl;

    return 0;

}