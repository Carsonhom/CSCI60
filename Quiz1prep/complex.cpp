#include "complex.h"

Complex::Complex()
{
  a_ = 0;
  b_ = 1;
}

Complex::Complex(double a, double b)
{
  a_ = a;
  b_ = b;
}

double Complex::real()
{
  return a_;
}

double Complex::imaginry()
{
  return b_;
}

double Complex::magnitude()
{
  return std::sqrt(std::pow(a_, 2) + std::pow(b_, 2));
}

