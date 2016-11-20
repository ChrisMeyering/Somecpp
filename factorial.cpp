#include <iostream>
#include <stdexcept>
using namespace std;

void error();
int factorial (int);
int main (){
  int n;
  try{
    cout << "Enter a positive integer: ";
    if (!(cin >> n))
      throw invalid_argument("Not a number.\n");
    if (n <= 0)
      throw n;
    else
      cout << factorial(n) << endl;
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

void error() {
  cout << "\033[1;31mERROR! \033[0m";

}
int factorial (int n){  
  if (n <= 0)
    return 1;
  else return n * factorial (n - 1);
}
