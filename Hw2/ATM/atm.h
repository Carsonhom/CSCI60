//atm.h
#ifndef ATM_H
#define ATM_H

#include "bankaccount.h"
#include <string>
#include <iostream>

class ATM
{
	private:
		int twenties_;
		int tens_;
	public:
    ATM();

    ATM(int twenties, int tens);

    int twenties()
    {
      return twenties_;
    }

    int tens()
    {
      return tens_;
    }

    BankAccount get_cash(int amount, BankAccount b);

    void operator +=(ATM& rhs);

    void restock(int new20s, int new10s);
};

#endif
