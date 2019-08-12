#include <iostream>
#include <string>
#include "node.h"
#include "lbiguint.h"

using namespace std;

int main(){
  lbiguint a = lbiguint("1234");
  cout<<a<<endl;
  lbiguint b = lbiguint("234");
  cout << b << endl;
  b = a;
  cout << b << endl;
}
