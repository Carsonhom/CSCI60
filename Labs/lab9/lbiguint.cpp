#include "lbiguint.h"

#include <cassert>
#include <sstream>

 lbiguint::lbiguint(){
   head = tail = new node (0, nullptr);
 }
 lbiguint::lbiguint (const std::string & s)
 {
   head = tail = new node (s.at(0)-'0');
   for (int i = 1; i < s.size(); i++)
   {
     node *temp = new node ((s.at(i)-'0'), head);
     head  = temp;
   }
 }

lbiguint::~lbiguint(){
  for (node *p = head; p != nullptr; p = head){
    node *temp = head->link();
    delete head;
    head = temp;
  }
  head = nullptr;
  tail = nullptr;
}

std::size_t lbiguint::size() const{
  size_t count = 0;
  for (node *p = head; p!=nullptr; p = p->link()){
    count++;
  }
  return count;
}

node::value_type lbiguint::operator [](std::size_t pos) const{
  size_t count = 0;
  for (node *p = head; p!=nullptr; p = p->link()){
    if (count == pos){
      return p->data();
    }
    count++;
  }
  return 0;
}

std::ostream & operator << (std::ostream & os, const lbiguint & a){
  for (int i = a.size()-1; i >= 0; i--){
    os<<a[i];
  }
  return os;
}

void lbiguint::operator =(const lbiguint & bag){
  if(size() < bag.size())
  {
    node * temp = head;
    for(node * p = bag.head; p != nullptr; p = p -> link())
    {
      temp -> set_data(p -> data());
      if(temp -> link() == nullptr && p -> link() != nullptr)
      {
        node * extra = new node();
        tail -> set_link(extra);
        tail = extra;
      }
      temp = temp -> link();
    }
  }
  else
  {
    node * temp = bag.head;
    for(node * p = head; p != nullptr; p = p -> link())
    {
      p -> set_data(temp -> data());
      if(temp -> link() == nullptr)
      {
        tail = p;
        node * next = p -> link();
        tail -> set_link(nullptr);
        for(node * j = next; j != nullptr; j = next)
        {
          next = j -> link();
          delete j;
        }
        return;
      }
      temp = temp -> link();
    }
  }
}
 /*unsigned short biguint::operator [](std::size_t pos) const
 {
     assert(pos < CAPACITY);
     return _data[pos];
 }



 int biguint::compare(const biguint & b) const{
     for(std::size_t i =CAPACITY-1; i>=0; --i){
         if(_data[i]>b._data[i])
             return 1;
         else if (_data[i]<b._data[i])
             return -1;

     }
     return 0;
 }



 void biguint::operator += (const biguint & b){
     int carry = 0;
     int next = 0;
     for(std::size_t i=0; i<CAPACITY; ++i){
         next = carry+_data[i]+b._data[i];
         _data[i]=next%10;
        carry=next/10;
     }
 }
 std::string biguint::toStdString() const
 {
     std::stringstream ss;
     ss << *this;
     return ss.str();
 }//We haven't talked about stringstreams; just ignore this, I was being lazy.
 std::ostream & operator << (std::ostream & os, const biguint & b)
 {

     for (int i = biguint::CAPACITY - 1; i >= 0; --i)
         os << b[i];
     return os;
 }

 std::istream & operator >> (std::istream & is, biguint & b)
 {
     std::string s;
     is >> s;
     b = biguint(s);
     return is;


 }

 bool operator <(const biguint& a, const biguint& b){
     return (a.compare(b)==-1);
 }

 bool operator <= (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) <= 0);
 }

 bool operator == (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) == 0);
 }

 bool operator != (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) != 0);
 }*/

//You do > and >=
