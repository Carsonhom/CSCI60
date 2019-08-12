#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
class Complex
{
  private:
    double a_;
    double b_;
  public:
    Complex();

    Complex(double a, double b);

    double real();

    double imaginry();

    double magnitude();
};





#endif
