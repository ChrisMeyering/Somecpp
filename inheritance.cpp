#include <iostream>
#include <stdexcept>
using namespace std;

class Rectangle {
  protected:
    int w;
    int l;
  public:
    Rectangle () : w(0), l(0) {}
    Rectangle (int wid, int len) : w(wid), l(len) {}
    void setWidth (int wid) {w = wid;}
    void setLength (int len) {l =len;}
    int getWidth() {return w;}
    int getLength () {return l;}
    virtual double getArea () {return w*l;}
};

class Triangle : public Rectangle {
  public:
    double getArea() {return (double)w*(double)l/2;}
};

void handleIntErrors(Rectangle& R);
void error();

int main () 
{
  Rectangle R = *new Rectangle();
  Triangle T = *new Triangle();
  do 
  {
    cout << "RECTANGLE:\n";
    handleIntErrors(R);
  } while (R.getWidth() == 0 || R.getLength() == 0);
  do
  {
    cout << "TRIANGLE:\n";
    handleIntErrors(T);
  } while (T.getWidth() == 0 || R.getLength() == 0);
  cout << "The area of a " << R.getWidth() << "*";
  cout <<  R.getLength() << " rectangle is " << R.getArea(); 
  cout << " squared units.\n";
  cout << "The area of a " << T.getWidth() << "*";
  cout <<  T.getLength() << " Triangle is " << T.getArea(); 
  cout << " squared units.\n";
}


void error() { 
  cout << "\033[1;31mERROR! \033[0m";
}

void handleIntErrors (Rectangle& R){
  int x;
  
  try 
  {
    cout << "Enter width: ";
    if(!(cin >> x)) throw invalid_argument("Not a number.\n");
    x > 0 ? R.setWidth(x) : throw x;
  }
  catch (int e1) 
  {
    error();
    cout << "(" << e1 << "): Positive integer expected! \n";
  }
  catch (invalid_argument & e1)
  {
    error();
    cout << e1.what();
    cin.clear();
    cin.ignore();
  }
  try 
  {
    cout << "Enter length: ";
    if(!(cin >> x)) throw invalid_argument("Not a number.\n");
    x > 0 ? R.setLength(x) : throw x;
  }
  catch (int e2) 
  {
    error();
    cout << "(" << e2 << "): Positive integer expected! \n";
  }
  catch (invalid_argument & e2)
  {
    error();
    cout << e2.what();
    cin.clear();
    cin.ignore();
  }
}
