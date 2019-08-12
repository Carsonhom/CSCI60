#ifndef DSET_H
#define DSET_H
#include "dUset.h"

class dSet: public dUset
{
public: 
	dSet();

	dSet(int a[], int s);

	void insert(int target);

};




#endif