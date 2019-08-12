#include "biguint.h"

#include <iostream>
#include <string>

using namespace std;

ostream& operator <<(ostream& out, biguint b)
{
  string str = "";
  string str1;
  for(int i = 0; i < b.CAPACITY; i++)
  {
    if(b[i] != 0)
    {
      str += to_string(b[i]);
    }
  }
  str1 = str;
  /*
  for(int j = str.length() - 1; j > 0; j--)
  {
    str1.at(str.length() - 1 - j) = str.at(j);
  }
  */
  for(int i = 0; i < str.length(); i++)
  {
    str1.at(i) = str.at(str.length() - 1 - i);
  }
  out << str1;
  return out;
}

biguint operator +(const biguint & b1, const biguint & b2)
{
  biguint a = biguint();
  a += b1;
  a += b2;
  return a;
}

biguint operator -(const biguint & lhs, const biguint & rhs)
{
  biguint a = biguint();
  a += lhs;
  a -= rhs;
  return a;
}

bool operator <(const biguint & lhs, const biguint & rhs)
{
  int compare = lhs.compare(rhs);
  if(compare == -1)
  {
    return true;
  }
  else return false;
}

bool operator <=(const biguint & lhs, const biguint & rhs)
{
  int compare = lhs.compare(rhs);
  if(compare <= 0)
  {
    return true;
  }
  else return false;
}

bool operator >(const biguint & lhs, const biguint & rhs)
{
  int compare = lhs.compare(rhs);
  if(compare == 1)
  {
    return true;
  }
  else return false;
}

bool operator >=(const biguint & lhs, const biguint & rhs)
{
  int compare = lhs.compare(rhs);
  if(compare >= 0)
  {
    return true;
  }
  else return false;
}

bool operator ==(const biguint & lhs, const biguint & rhs)
{
  int compare = lhs.compare(rhs);
  if(compare == 0)
  {
    return true;
  }
  else return false;
}

bool operator !=(const biguint & lhs, const biguint & rhs)
{
  int compare = lhs.compare(rhs);
  if(compare != 0)
  {
    return true;
  }
  else return false;
}

int main()
{
  biguint a = biguint("1234");
  biguint b = biguint("1234");
//  b -= a;
  cout << b << endl;
  int compare = a.compare(b);
  cout << compare << endl;
  cout << b.toString() << endl;
  /*if(a != b)
  {
    cout << "true" << endl;
  }
  else cout << "false" << endl;*/

return 0;
}
