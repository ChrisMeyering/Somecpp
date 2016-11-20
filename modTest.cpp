#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
  srand (time(NULL));
  int min = 100;
  int max = 0;
  for (int i = 0; i < 200; i++) {
    int randNum = rand() % 20 + 20;
    if (randNum < min)
      min = randNum;
    if (randNum > max)
      max = randNum;
  }
  cout << "max = " << max << endl;
  cout << "min = " << min << endl;
}
