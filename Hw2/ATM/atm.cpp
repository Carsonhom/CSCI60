//atm.cpp
#include "atm.h"

ATM::ATM()
{
  twenties_ = 0;
  tens_ = 0;
}

ATM::ATM(int twenties, int tens)
{
  twenties_ = twenties;
  tens_ = tens;
}

BankAccount ATM::get_cash(int amount, BankAccount b)
{
  if((double)amount > b.get_balance())
  {
    std::cout << "You are unable to withdraw $" << amount << " because your balance is insufficient" << std::endl;
    return b;
  }
  if(amount <= 0)
  {
    std::cout << "The amount requested is invalid" << std::endl;
    return b;
  }
  int twenties = 0;
  int tens = 0;
  while(amount >= 20)
  {
    amount -= 20;
    twenties++;
  }
  while(amount < 20 && amount > 0)
  {
    amount -= 10;
    tens++;
  }
  if(twenties > twenties_ || tens > tens_)
  {
    std::cout << "This ATM does not have enough cash to withdraw the amount requested" << std::endl;
    return b;
  }
  twenties_ -= twenties;
  tens_ -= tens;
  std::cout << "You have recieved " << twenties << " twenty dollar bills and " << tens << " ten dollar bills" << std::endl;
  double amt = (double)amount;
  b.withdraw(amt);
  return b;
}

void ATM::operator +=(ATM& rhs)
{
  twenties_ += rhs.twenties();
  rhs.twenties_ = 0;
  tens_ += rhs.tens();
  rhs.tens_ = 0;
  
}

void ATM::restock(int new20s, int new10s)
{
  twenties_ += new20s;
  tens_ += new10s;
}

