// Author: Chris Meyering
// Class: CS 110C
// Created: Monday October 1st 2014
// Semester: Fall 2014
// Instructor: Steve Abensohn
// Input: a positive integer: n
//        an integer greater or equal to 2: base
// Output: This program assumes the user enters an integer
//         base 10. It will convert and print that number in
//         the base the user entered.
// Last Modified: Monday October 3rd 2014 
// Modified by: Chris Meyering

#include <iostream>
#include <cstdio>
using namespace std;
int display(int, int);

int main()
{
  int n;
  int base;
  do
  {
    try //Throw if user enters invalid value for 'n'. 
    {
      cout << "Enter a positive integer to convert (enter -1 to exit): ";
      if (!(cin >> n) || (n < 0))
        throw n;
    }
    catch (int e1)
    {
      if (e1 == -1)
        cout << "See you soon!\n";
      else
        printf ("Invalid entry: %d\n", e1);
      return 0;
    }
    try //Throw if user enters invalid value for 'base'.
    {
      cout << "Enter the new base: ";
      if (!(cin >> base) || (base <= 1))
        throw base;
    }
    catch (int e2)
    {
      cout << "The base must be an integer greater or equal to 2: ";
      cout << e2 << "\n";
      return 0;
    }
    cout << n;
    cout << display (n, base) << " base " << base << "\n\n";
  } while (true);
}


// Will convert a number (n) from base 10 to base (base).
int display(int n,int base)
{
  int convertedNumber = 0;
  if(n == 0 || base==10)
    cout << " base 10 is ";
  else {
    convertedNumber += (n % base + 10 * display(n / base, base));  
    return convertedNumber;
    cout << (n % base);
  }
  return 0;
}
