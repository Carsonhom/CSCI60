#include <iostream>
#include "Rational.h"

using namespace std;

bool operator == (Rational lhs, Rational rhs) 
{
    if(lhs.numer() * rhs.denom() == rhs.numer() * lhs.denom()) return true;
    else return false;
}

int main(int argc, char *argv[])
{
    Rational r1 = Rational(1, 2);
    Rational r2 = Rational(3, 4);

    //Rational r = r1.mult(r2);
    Rational r = r1 * r2;


    return 0;
}




/*
 *
#include <iostream>

using namespace std;

struct Rational{
    int numer;
    int denom;
};

Rational mult(Rational a, Rational b);

Rational plus(Rational a, Rational b);

int main(int argc, char *argv[])
{
    Rational r1 = {1, 2}, r2 = {3, 4};
    Rational r = mult(r1, r2);

    cout<<r.numer<<"/"<<r.denom<<endl;
    return 0;
}


Rational mult(Rational a, Rational b){
    Rational ans;
    ans.numer = (a.numer*b.numer);
    ans.denom = (a.denom*b.denom);
    return ans;
}
Rational plus(Rational a, Rational b){
    Rational ans;

    return ans;
}
*/
