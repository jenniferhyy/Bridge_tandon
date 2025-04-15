#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

class Money {
  public:
    friend Money operator+(const Money &amount1, const Money &amount2);
    Money& operator+=(const Money &amount);
    friend Money operator-(const Money &amount1, const Money &amount2);
    friend Money operator-(const Money &amount);
    friend bool operator==(const Money &amount1, const Money &amount2);
    friend bool operator<(const Money &amount1, const Money &amount2);
    Money(long dollars, int cents);
    Money(long dollars);
    Money();
    double get_value() const;
    void set_value(long cents_in);
    void set_value(double amount);
    friend istream &operator>>(istream &ins, Money &amount);
    friend ostream &operator<<(ostream &outs, const Money &amount);
  private:
    long all_cents;
};

class Check {
  public: 
    Check (int check_number, long dollars, int cents, bool is_cashed);
    Check (int check_number, long dollars, bool is_cashed);
    Check ();
    int get_check_number() const;
    Money get_amount_of_check() const;
    bool get_is_cashed() const;
    void set_check_number(int check_number); 
    void set_amount_of_check(const Money& amount_of_check);
    void set_is_cashed(bool is_cashed);
    friend bool operator <(const Check& lhs, const Check& rhs);
    friend istream &operator>>(istream &ins, Check& check);
    friend ostream &operator<<(ostream &outs, const Check& check);
  private: 
    int check_number;
    Money amount_of_check; 
    bool is_cashed;
};

int digit_to_int(char c);
Money get_total_cashed_checks(const Check checks[], int number_of_checks);
Money get_total_uncashed_checks(const Check checks[], int number_of_checks);
Money get_total_deposits(const Money deposits[], int number_of_deposits);
void list_of_cashed_checks(const Check checks[], int number_of_checks);
void list_of_uncashed_checks(const Check checks[], int number_of_checks);

int main(){
  int number_of_checks;
  cout << "Checkbook Balancing Program:" << endl;
  cout << "Please enter the following, separated by spaces: " << endl;
  cout << "Number on the check, the check amount, whether the check was cashed" << endl;
  cout << "(1 for cashed checks / 0 for uncashed checks) (for example, 13 $12.20 1): " << endl;
  cout << "Firstly, how many checks are you depositing? " << endl;
  cin >> number_of_checks;
  cout << "Please enter the checks in the prescribed format above: " << endl;
  Check* checks = new Check[number_of_checks];
  for (int i = 0; i < number_of_checks; i++){
    cin >> checks[i];
  }

  int number_of_deposits;
  cout << "Please enter the deposits in the following format ($##.##), on separate lines: " << endl;
  cout << "Firstly, how many deposits are you making? " << endl;
  cin >> number_of_deposits;
  cout << "Please enter the deposits in the prescribed format above: " << endl;
  Money* deposits = new Money[number_of_deposits];
  for (int i = 0; i < number_of_deposits; i++){
    cin >> deposits[i];
  }

  Money previous_balance;
  cout << "Please enter your previous account balance in the following format ($##.##): ";
  cin >> previous_balance; 
  cout << endl;

  Money total_cashed_checks, total_uncashed_checks, total_deposits, curr_bank_balance, customer_balance;
  total_cashed_checks = get_total_cashed_checks(checks, number_of_checks);
  total_uncashed_checks = get_total_uncashed_checks(checks, number_of_checks); 
  total_deposits = get_total_deposits(deposits, number_of_deposits);
  curr_bank_balance = previous_balance - total_cashed_checks + total_deposits;
  customer_balance = previous_balance - (total_cashed_checks + total_uncashed_checks) + total_deposits;
    
  cout << "The total of the checks cashed is: " << total_cashed_checks << endl;
  cout << "The total of the deposits is: " << total_deposits << endl;
  cout << "The new balance should be: " << curr_bank_balance << endl;
  cout << "The new balance if all checks are cashed is: " << customer_balance << endl;
  cout << "The difference is: " << total_uncashed_checks << endl; 
  cout << "The list of checks (cashed): " << endl;
  list_of_cashed_checks(checks, number_of_checks);
  cout << "The list of checks (not cashed): " << endl; 
  list_of_uncashed_checks(checks, number_of_checks);

  delete[] checks;
  delete[] deposits;
  
  return 0;  
}

Money& Money::operator+=(const Money &amount) {
    this->all_cents += amount.all_cents;
    return *this;
}

Money::Money(long dollars, int cents){
    if (dollars * cents < 0){
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100){}

Money::Money() : all_cents(0){}

double Money::get_value() const{
    return (all_cents * 0.01);
}

void Money::set_value(long cents_in){
    all_cents = cents_in;
}

void Money::set_value(double amount){
    all_cents = amount * 100;
}

Money operator+(const Money &amount1, const Money &amount2){
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool operator==(const Money &amount1, const Money &amount2){
    return (amount1.all_cents == amount2.all_cents);
}

Money operator-(const Money &amount1, const Money &amount2){
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator-(const Money &amount){
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator<(const Money &amount1, const Money &amount2){
    if (amount1.all_cents < amount2.all_cents)
        return true;
    return false;
}

istream &operator>>(istream &ins, Money &amount){
    char one_char, decimal_point, digit1, digit2; 
    long dollars;
    int cents;
    bool negative;
    ins >> one_char;
    if (one_char == '-'){ // Standard dash
        negative = true;
        ins >> one_char; // read '$'
    }
    else
        negative = false;
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)){
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;
    return ins;
}

int digit_to_int(char c){
    return (static_cast<int>(c) - static_cast<int>('0'));
}

ostream &operator<<(ostream &outs, const Money &amount){
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0)
        outs << "− $" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}


Check::Check(int check_number, long dollars, int cents, bool is_cashed) : check_number(check_number), amount_of_check(Money(dollars, cents)), is_cashed(is_cashed) {}

Check::Check(int check_number, long dollars, bool is_cashed) : check_number(check_number), amount_of_check(Money(dollars)), is_cashed(is_cashed) {}

Check::Check(): check_number(0), amount_of_check(Money()), is_cashed(false) {}

int Check::get_check_number() const{
  return check_number;
}

Money Check::get_amount_of_check() const{
  return amount_of_check;
}

bool Check::get_is_cashed() const{
  return is_cashed;
}

void Check::set_check_number(int check_number){
  this-> check_number = check_number;
} 

void Check::set_amount_of_check(const Money& amount_of_check){
  this-> amount_of_check = amount_of_check;
}

void Check::set_is_cashed(bool is_cashed){
  this-> is_cashed = is_cashed;
};

bool operator <(const Check& lhs, const Check& rhs){
  return lhs.check_number < rhs.check_number;
}

istream &operator>>(istream &ins, Check& check){
  string is_cashed;
  ins >> check.check_number >> check.amount_of_check >> is_cashed;
  if (is_cashed == "1"){
    check.is_cashed = true;
  } else if (is_cashed == "0") {
    check.is_cashed = false;
  } else {
    cout << "Error, illegal form of input re whether check is cashed.";
    exit(1);
  }
  return ins;
}

ostream &operator<<(ostream &outs, const Check& check){
  outs << check.check_number << ' ' << check.amount_of_check << ' ';
  if (check.is_cashed){
    outs << "Cashed";
  } else {
    outs << "Not cashed";
  }
  return outs;
}

Money get_total_cashed_checks(const Check checks[], int number_of_checks){
  Money temp; 
  for (int i = 0; i < number_of_checks; i++){
    if (checks[i].get_is_cashed()){
      temp += checks[i].get_amount_of_check();
    }
  }
  return temp;
}

Money get_total_uncashed_checks(const Check checks[], int number_of_checks){
  Money temp; 
  for (int i = 0; i < number_of_checks; i++){
    if (!checks[i].get_is_cashed()){
      temp += checks[i].get_amount_of_check();
    }
  }
  return temp;
}

Money get_total_deposits(const Money deposits[], int number_of_deposits){
  Money temp;
  for (int i = 0; i < number_of_deposits; i++){
    temp += deposits[i];
  }
  return temp;
}

void list_of_cashed_checks(const Check checks[], int number_of_checks){
  for (int i = 0; i < number_of_checks; i++){
    if (checks[i].get_is_cashed()){
      cout << checks[i] << endl;
    }
  }
}

void list_of_uncashed_checks(const Check checks[], int number_of_checks){
  for (int i = 0; i < number_of_checks; i++){
    if (!checks[i].get_is_cashed()){
      cout << checks[i] << endl;
    }
  }
}
