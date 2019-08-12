#include "dbiguint.h"

#include <iostream>
#include <string>

using namespace std;

std::ostream & operator << (std::ostream & out, const dbiguint & b)
{
  string str = "";
  string str1;
  for(int i = 0; i < b.size(); i++)
  {
      str += to_string(b[i]);
  }
  str1 = str;
  for(int i = 0; i < str.length(); i++)
  {
    str1.at(i) = str.at(str.length() - 1 - i);
  }
  out << str1;
  return out;
}

std::istream & operator >> (std::istream & in, dbiguint & b)
{
  string str = "";
  in >> str;
  // cout << str;
  dbiguint newdata = dbiguint(str);
  b = newdata;
  return in;
}

dbiguint operator +(const dbiguint & b1, const dbiguint & b2)
{
  dbiguint a = dbiguint();
  a += b1;
  a += b2;
  return a;
}

dbiguint operator -(const dbiguint & lhs, const dbiguint & rhs)
{
  dbiguint a = dbiguint();
  a += lhs;
  a -= rhs;
  return a;
}

dbiguint operator *(const dbiguint & lhs, const dbiguint & rhs)
{
  dbiguint a = dbiguint();
  a += lhs;
  a *= rhs;
  return a;
}

bool operator <(const dbiguint & lhs, const dbiguint & rhs)
{
  if(lhs.compare(rhs) == -1)
  {
    return true;
  }
  else return false;
}

bool operator <=(const dbiguint & lhs, const dbiguint & rhs)
{
  if(lhs.compare(rhs) <= 0)
  {
    return true;
  }
  else return false;
}

bool operator >(const dbiguint & lhs, const dbiguint & rhs)
{
  if(lhs.compare(rhs) == 1)
  {
    return true;
  }
  else return false;
}

bool operator >=(const dbiguint & lhs, const dbiguint & rhs)
{
  if(lhs.compare(rhs) >= 0)
  {
    return true;
  }
  else return false;
}

bool operator ==(const dbiguint & lhs, const dbiguint & rhs)
{
  if(lhs.compare(rhs) == 0)
  {
    return true;
  }
  else return false;
}

bool operator !=(const dbiguint & lhs, const dbiguint & rhs)
{
  if(lhs.compare(rhs) != 0)
  {
    return true;
  }
  else return false;
}

int main()
{
  dbiguint a = dbiguint("1234");
  dbiguint c = dbiguint("02234");
  dbiguint b = dbiguint();
  dbiguint d = dbiguint("12");
  dbiguint e = dbiguint("12");

  cout << a.size() << endl;
  cout << a[2] << endl;
  cout << a << endl;
  // a.reserve(5);
  // cout << a << endl;
  //a += c;
  cout << c << endl;
  cout << a.compare(c) << endl;
//  b -= a;
  // cout << b << endl;
  // int compare = a.compare(b);
  // cout << compare << endl;
  // cout << b.toString() << endl;
  if(a != b)
  {
    cout << "true" << endl;
  }
  else cout << "false" << endl;
  // a = c;
  // cout << (a = c) << endl;
  cout << a << endl;
  // c -= a;
  dbiguint f = c - a;
  cout << f << endl;
  
  // d *= e;
  cout << e * a << endl;

  dbiguint g = dbiguint();
  cout << "Enter a dbiguint: ";
  cin >> g;
  cout << g << endl;
  cout << "end" << endl;
  return 0;
}
