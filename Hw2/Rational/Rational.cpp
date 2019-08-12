
#include "Rational.h"

Rational::Rational(int n, int d){
  numer_ = n;
  denom_ = d;
}
Rational::Rational(){
  numer_ = 0;
  denom_ = 1;
}



Rational Rational::plus(Rational b){//Full function definition after main
  Rational ans;//:: is the scope operator, changes the scope of the thing we're defining
  ans.numer_ = (numer_*b.denom_+b.numer_*denom_);
  ans.denom_ = (denom_*b.denom_);
  ans.reduce();
  return ans;
}
Rational Rational::operator *(Rational b){
    Rational ans;//Rational:: goes before the name of the thing whose scope you're changing
    ans.numer_ = (numer_*b.numer_);
    ans.denom_ = (denom_*b.denom_);
    ans.reduce();
    return ans;
}

void Rational::operator +=(Rational rhs) 
{
  numer_ = numer_ * rhs.denom_;
  denom_ = denom_ * rhs.denom_;
}

void Rational::reduce()
{
  int gcd = numer_;
  int den = denom_;

  while(gcd != den)
  {
    if (gcd > den)
    {
      gcd -= den;
    }
    else 
    {
      den -= gcd;
    }
  }

  numer_ = numer_ / gcd;
  denom_ = denom_ / gcd;

}