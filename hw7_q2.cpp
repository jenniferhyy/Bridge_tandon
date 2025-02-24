#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main(){
  int M;
  cout << "Please enter a positive integer M (>=2): " << endl;
  cin >> M;
  cout << "Perfect numbers between 2 and " << M << ": ";
  for(int i = 2; i <= M; i++){
    if(isPerfect(i)){
      cout << i << " "; 
    }
  }
  cout << endl;
  cout << "Pairs of amicable numbers between 2 and " << M << ": ";
  int CountDivs1, SumDivs1, CountDivs2, SumDivs2;
  for (int i = 2; i <= M; i++){
    analyzeDividors(i, CountDivs1, SumDivs1);
    analyzeDividors(SumDivs1, CountDivs2, SumDivs2);
    if (i == SumDivs2 && SumDivs2 <= M){
      cout << "(" << i << ", " << SumDivs1 << ") ";
    }
  }
  return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs){
  int SumDivs = 1;
  int CountDivs = 1;
  for (int i = 2; i <= sqrt(num); i++){
    if (num % i == 0){
      SumDivs = SumDivs + i + num/i;
      CountDivs = CountDivs + 2;
    }
  }
  outSumDivs = SumDivs;
  outCountDivs = CountDivs;
}

bool isPerfect(int num){
  int CountDivs, SumDivs;
  analyzeDividors(num, CountDivs, SumDivs);
  return (num == SumDivs);
}

