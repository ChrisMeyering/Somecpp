#include <iostream>
using namespace std;

int fibonacci(int n);

int main (){
  int num = 1;
  for (int i = 0; i <= 10; i++){
    cout << fibonacci(num) << ", ";
    num ++;
  }
  cout << fibonacci(num) << ".\n";
}

int fibonacci(int n){
  if (n < 1){
    cout << "\n Error: non positive argument.\n";
  }
  else if (n == 1 || n == 2)
    return 1;
  else
    return (fibonacci(n - 1) + fibonacci(n - 2));
  return 0;
}
