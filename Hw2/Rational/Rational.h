#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>
class Rational{
private:
    int numer_;// trailing _:  This is a private variable
    int denom_;
public:
    Rational(int n, int d);//Don't need to comment constructors and getters
    Rational();
    int numer(){  return numer_; }//Don't bother with forward declaration for one-liner
    int denom(){  return denom_; }

    //pre: none
    //post: returns a Rational that is the result of multiplyinging this Rational and the Rational passed in.
    //The result is not reduced; the denominator will be the product of the denominators of the operands.
    Rational operator *(Rational b);//used to be mult

    //pre: none
    //post: returns a Rational that is the result of adding this Rational and the Rational passed in.
    //The result is not reduced; the denominator will be the product of the denominators of the operands.
    Rational operator +(Rational b);


    //pre: none
    //post: returns true if this Rational has a smaller value than the Rational passed in.
    bool operator <(Rational rhs);
    //overload <, <=, ==

    void operator +=(Rational rhs);

    void reduce();

};

#endif
