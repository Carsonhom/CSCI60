#include "biguint.h"


biguint::biguint() //biguint default constructor
{
  for(int i = 0; i < CAPACITY; i++)
  {
    data_[i] = 0;
  }
}

biguint::biguint(const std::string & str) //biguint constructor which converts string into biguint
{
  std::string str2 = str;
  for(int i = 0; i < str.length(); i++)
  {
  str2.at(i) = str.at(str.length() - 1 - i);
  }


/*
  for(int i = str.length() - 1; i >= 0; i--)
  {
    str2.at(str.length() - 1 - i) = str.at(i);
  }
  */
  for(int j = 0; j < str2.length(); j++)
  {
    data_[j] = str2.at(j) - '0';
  }
  if(str2.length() < CAPACITY)
  {
    for(int k = str.length(); k < CAPACITY; k++)
    {
      data_[k] = 0;
    }
  }
}


//  for(int i = 0; i <= str.length(); i++)
//  {
//    data_[i] = (str.at(str.length() - i) - '0');
//  }
//  if(str.length() < CAPACITY)
//  {
//    for(int j = str.length() + 1; j < CAPACITY; j++)
//    {
//      data_[j] = 0;
//    }
//  }
//}


unsigned short biguint::operator [](std::size_t pos) const //accesses the digit in position pos
{
  assert(pos < CAPACITY);
  return data_[pos];
}

void biguint::operator +=(const biguint & b) 
{
  for(std::size_t i = CAPACITY; i > 0; i--)
  {
    if(data_[i - 1] + b.data_[i - 1] >= 10)
    {
      data_[i - 1] = data_[i - 1] + b.data_[i - 1] - 10;
      data_[i - 2] += 1;
    }
    else
    {
      data_[i - 1] += b.data_[i - 1];
    }
  }

}

void biguint::operator -=(const biguint & b)
{
  for(std::size_t i = CAPACITY; i > 0; i--)
  {
    if(data_[i - 1] - b.data_[i - 1] < 0)
    {
      data_[i - 2] -= 1;
      data_[i - 1] = 10 + data_[i - 1] - b.data_[i - 1];
    }
    else 
    {
      data_[i - 1] -= b.data_[i - 1];
    }
  }
}

int biguint::compare(const biguint & b) const //compares 2 biguints
{
  for(std::size_t i = CAPACITY; i > 0; i--)
  {
    if(data_[i - 1] > b.data_[i - 1])
    {
      return 1;
    }
    else if(data_[i - 1] < b.data_[i - 1])
    {
      return -1;
    }
    else if(data_[i - 1] == b.data_[i - 1] && i == 1)
    {
      return 0;
    }
  }
}

std::string biguint::toString() //converts a biguint into a string
{
  std::string str = "";
  std::string str1;
  for(int i = 0; i < CAPACITY; i++)
  {
    if(data_[i] != 0)
    {
      str += '0' + data_[i];
     // str += std::to_string(data_[i]);
    }
  }
  str1 = str;
  for(int i = 0; i < str.length(); i++)
  {
    str1.at(i) = str.at(str.length() - 1 - i);
  }
  return str1;
}

