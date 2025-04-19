#include <iostream>
#include <vector>
using namespace std;

class Measurement {
        int feet;
        int inches;
        void normalise();
    public: 
        // 0 is a default parameter, and there's just 1 constructor (Measurement(int totalInches = 0) that can take in 1 value)
        Measurement(int totalInches = 0):inches(totalInches){normalise();}
        /* or: Measurement() : inches(0) {normalise();} 
               Measurement(int totalInches) : inches(totalInches){normalise();} */
        int getTotalInches() const {return feet * 12 + inches;}
        void setInches(int newinches);
        void setFeet(int newFeet) {feet = newFeet;}
        int getFeet() const {return feet;} 
        int getInches() const {return inches;}
        Measurement operator+(const Measurement& rhs); // too long to put constructor here
        Measurement& operator++();
        Measurement++ (int);
        J
};
Measurement Measurement::operator+(const Measurement& rhs){
    Measurement temp;
    temp.setInches(getTotalInches()+rhs.getTotalInches());
}
void Measurement::setInches(int newinches){
    inches = newinches;
    normalise();
}

void Measurement::normalise(){
    if (inches >= 12){
        feet += (inches / 12);
        inches %= 12;
    }
    while (inches < 0){
        feet -= 1;
        inches += 12;
    }
}

void func1(Measurement m){ // cannot pass a vector
}
void func2(Measurement& m){
    m.setInches(100); // the copy will be destroyed if not named const
}
void func3(const Measurement& m){
    cout << m.getTotalInches() << endl; //this is const bc output not changed
}
void vectorfunc1(vector<int> v){}

void vectorfunc2(vector<int>& v){
    v.clear(); // also destroyed
}
void vectorfunc3(const vector<int>& v){
    /* 
    v.clear(); // not possible bc const 
    v[0] = 100; // also not poss bc const
    */
    cout << v[0] <<endl; // possible
}
int main(){
    Measurement m1;
    Measurement m2(42);
    Measurement m3 = m1+m2;
    int x = 5;
    int y = 10;
    int z = x+y; // z.operator = (x.operator+(y)); or z.operator = (operator+(x,y));

    /* vector<int> v;
    for (int i = 0; i<1000000000; i++)
        v.push_back(i);
    vectorfunc2(v); */
}
