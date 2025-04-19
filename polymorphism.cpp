#include <iostream> 
using namespace std;

class Pet{                                                   // BASE CLASS
  string name;
  int petID;
public: 
  Pet(int newID = 0){petID = newID;}
  string getName() const {return name;}
  virtual void setName(string newName){name = newName;}
  virtual void speak() const = 0; // PURE VIRTUAL FUNCTION, causing pet class to become abstract i.e. cannot instantiate the Pet class (can't create pet)
};

class Cat : public Pet{ // Cat IS-A pet                       // DERIVED CLASS
  double whiskerlength;  
public: 
  Cat(): Pet(10000){} // call to BASE constructor, else newID = 0 
  void speak()const {cout << "MEOW";}
  void setLength(double whiskerlength);
  void getLength() const {return whiskerlength;}
  void setName(string newName); // overrides the base version of function
  Cat& operator=(const Pet&); // build a cat on top of the components for pet
};

// NB: NEW CAT, NEW WHISKER LENGTH. NEED TO OVERRIDE BY TYING SETNAME WITH RESETTING WHISKER LENGTH
void Cat::setName(string newName){  // call base function of function, need scope resolution operator "::"
   whiskerLength = 0;
   Pet::setName(newName);  
}

int main1(){
  Pet p; 
  Pet* pptr; // Pet pptr can point to pet and any derived class whose base class is Pet (e.g. Cat / Jaguar : Pet)
  Cat c;     
  Cat* cptr;
  p = c; // OK - slicing, (cnp) overlapping elements assigned from cat to pet 
  c = p; // OK - upgrade from pet to cat ok if operator=(const Pet&) is overloaded;
  pptr = &c; // OK, polymorphism  // see cmt above, base class pptr can point to object of derived class but x get rid of any base class functions.
  cptr = &p; // NOT ALLOWED - derived class pointer is going to have functions available that does not exist in set class
}


class Dog : public Pet {
  double earsize;
public: 
  Dog() : Pet(2000) {}
  void speak() const { cout << "Woof!" << endl; }
  void setSize(double newSize) { earSize = newSize; }
  double getSize() const { return earSize; }
};

int main4() {
  Pet** pArray = new Pet* [3];
  pArray[0] = new Cat(); 
  pArray[1] = new Dog(); 
  pArray[2] = new Cat(); 
  for (int i = 0; i < 3; i++){
    pArray[i] -> speak(); // MEOW, WOOF, MEOW
  }
  return 0;
}


// ******************************************************************************************************************

class Base {
  int x; 
public: 
  Base (int newx = 0) : x(newx){}
  void printVal() const { cout << x << endl; }
  //   virtual void printVal() const { cout << x << endl; } // this would cause bpbtr to follow where it is pointing re function 
  int getVal() const { return x; }
};

class Derived : public Base {
public: 
  Derived(int newx = 0) : Base(newx) {}
  void printVal() const { cout << getVal()*100 << endl; }
};

// ******************************************************************************************************************

class A {
  int* ptr;
public: 
  A(int newval = 0) { ptr = new int(newval); } // constructor 
  virtual ~A() { delete ptr; } // solution where ptr A points to B
  A(const A& rhs) { ptr = new int(*rhs.ptr); } // copy constructor, used to create a new A object as a copy of an existing A object.
  A& operator=(const A& rhs);
};

// ** DESTRUCTOR SHOULD ALWAYS BE VIRTUAL!!!!

A& A::operator=(const A& rhs) {
  if (this==&rhs)
      return *this;
  *ptr = *rhs.ptr;
  return *this;
}

void func1() {
  A* temp = new A();
  delete temp; 
}

class B : public A {
  double * otherptr;
public:
  B(double d = 0, int x = 0) : A(x) {otherptr = new double(d); }
  virtual ~B() { delete otherptr; } // solution for pointer A pointing to B
  B(const B& rhs) : A(rhs) { otherptr = new double(*rhs.otherptr);
  B& operator=(const B& rhs);
};

B& B::operator=(const B& rhs) {
  if (this==&rhs)
      return *this;
  *otherptr = *rhs.otherptr;
  A::operator=(rhs); // call the base version to do its copying
  return *this;
}

void func2(){
  B temp;
  delete temp; 
  // BUT MEMORY LEAK IF: A* temp = new B(); --> bc A still points to the function of A, destructor destroys pointer to A but not B 
}

int main2(){
  for (int i = 0; i < 10000000; i++){
    func1();
    func2();
} 
  
/*  Base b1(1); 
  Derived b2(2); 
  b1.printVal();     // 1
  d1.printVal();     // 200
  b1 = d1;           // imports elements from d1 to b1
  b1.printVal();     // 2, newx = 2, functions in b1 stays the same
  Base* bptr = &b1; 
  bptr->printVal();  // 2
  bptr = &d1;        // Base ptr points to Derived object. Derived object holds x = 2
  bptr->printVal();  // 2, C++ uses function based on where the ptr comes from (Base) = PROBLEM!!! Unless function is virtual... = 200
*/
  
  }




