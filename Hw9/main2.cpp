#include <iostream>
#include "lbag.h"
using namespace std;

int main(int argc, char *argv[])
{
  lbag<int> b, d;
  b.insert(5);
  b.insert(2);
  b.insert(7);
  b.insert(1);
  // cout<<b<<endl;
  d = b;
  d += b;
  cout << d << endl;
  lbag<int> e;
  e = d + b;
  d.erase(1);
  cout << d << endl;

  // cout<<b<<endl;
  // cout<<d<<endl;
  // d.insert(5);
  // lbag<int> a(d);
  // cout<<b<<endl;
  // cout<<d<<endl;
  // cout<<a<<endl;
  // cout<<a.count(5)<<endl;
  // cout<<a.size()<<endl;



    return 0;
}
