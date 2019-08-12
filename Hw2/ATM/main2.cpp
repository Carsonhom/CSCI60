//main2.cpp
#include "atm.h"
#include "bankaccount.h"
#include <iostream>
#include <string>

using namespace std;
bool operator ==(ATM lhs, ATM rhs)
{
  if(lhs.twenties() == rhs.twenties() && lhs.tens() == rhs.tens())
  {
    return true;
  }
  else return false;
}

ostream& operator <<(ostream& out, ATM a)
{
  string str = "There are " + to_string(a.twenties()) + " twenty dollar bills and " + to_string(a.tens()) + " ten dollar bills in this atm"; 
  out << str;
  return out;
}

int main()
{
BankAccount b = BankAccount(123, 200, 222, "Tim");
cout << b << endl;

ATM atm1 = ATM(25, 25);
cout << atm1 << endl;

int amnt;
cout << "How much money would you like to withdraw? : ";
cin >> amnt;
atm1.get_cash(amnt, b);

int twenties;
int tens;
cout << "How many twenty dollar bills would you like to restock into the ATM? : ";
cin >> twenties;
cout << "How many ten dollar bills would you like to restock into the ATM? : ";
cin >> tens;
atm1.restock(twenties, tens);
cout << atm1 << endl;

int twenty;
int ten;
cout << "We are creating a new ATM, how many twenty dollar bills would you like it to have? : ";
cin >> twenty;
cout << "How many ten dollar bills would you like the new ATM to have? : ";
cin >> ten;
ATM atm2 = ATM(twenty, ten);
cout << atm2 << endl;

if(atm1 == atm2) 
{
  cout << "The two ATMs are equal" << endl;
}
else cout << "The two ATMs are not equal" << endl;


atm1 += atm2;
cout << "Adding the two ATMs, we are left with one ATM the contains " + to_string(atm1.twenties()) + " twenty dollar bills and an ATM with " + to_string(atm1.tens()) + " ten dollar bills" << endl;


	return 0;
}
