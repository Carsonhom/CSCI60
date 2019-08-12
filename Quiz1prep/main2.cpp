#include "complex.h"

#include <iostream>
#include <cmath>

using namespace std;
double operator +(Complex lhs, Complex rhs)
{
  return ((lhs.real() + rhs.real()) + (lhs.imaginry() + rhs.imaginry()));
}

bool operator ==(Complex lhs, Complex rhs)
{
  if((lhs.real() + lhs.imaginry()) == (rhs.real() + rhs.imaginry()))
  {
    return true;
  }
  else return false;
}

ostream& operator <<(ostream& out, Complex com)
{
  out << to_string(com.real()) + " + + " + to_string(com.imaginry());
  return out;
}


int main()
{
  double a;
  double b;
  cout << "What is the real number? : ";
  cin >> a;
  cout << "What is the imaginary number? : ";
  cin >> b;

  Complex x = Complex(a, b);

  cout << to_string(x.real()) << endl;
  cout << to_string(x.imaginry()) << endl;

  Complex y = Complex(a, b);

  double z = x + y;
  cout << to_string(z) << endl;

  cout << a == b;
  cout << '\n';

  cout << to_string(x.magnitude()) << endl;



  return 0;
}
