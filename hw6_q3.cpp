#include <iostream>
using namespace std; 

int factor(int n);
double eApprox(int n);

int main(){
  cout.precision(30);
  for (int n = 1; n <= 15; n++) {
    cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
  }
  return 0;
}

int factor(int n){
  factor = 1;
  for (int i = 1; i <= n; i++){
    factor = factor * i;
  }
  return factor;
}

double eApprox(int n){
  double e = 1.0;
  for (int i = 1; i <= n; i++){
    e += 1.0/(factor(i));
  }
  return e;
}
