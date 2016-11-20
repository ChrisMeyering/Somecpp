#include <iostream>
#include <stdexcept>
using namespace std;

int sumUpTo (int n);
void error();

int main (){
  int n;
  try{
    cout << "Enter a positive integer: ";
    if (!(cin >> n)) 
      throw invalid_argument("Not a number.\n");
    if (n <= 0) 
      throw n;
    else 
      cout << sumUpTo(n) << endl;
  }
  catch (invalid_argument & e1) {
    error();
    cout << e1.what();
    cin.clear();
    cin.ignore();
  }
  catch (int e1) {
    error();
    cout << "(" << e1 << "): Positive integer expected!\n";
  }
}

int sumUpTo (int n){
  int sum = 0;
  if (n == 1)
    sum = 1;
  else {
    sum = n + sumUpTo(n - 1);
    return sum;
  }
  return 1;
}

void error() {
  cout << "\033[1;31mERROR! \033[0m";
}
