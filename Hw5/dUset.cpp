#include "dUset.h"
#include <iostream>

dUset::dUset() 
{
	dynamicBag();
}

dUset::dUset(int a[], int s)
{
	dynamicBag(a, s);
	for(size_type i = 0; i < s; ++i)
	{
		int dupes = 0;
		if(this -> count(a[i]) < 1)
		{
			// dupes = (this -> count(a[i]));
			// for(int j = 1; j < dupes; ++j)
			// {
			// 	this -> erase_one(a[j]);
			// }
			this -> dynamicBag::insert(a[i]);
		}
	}
}

void dUset::insert(int target)
{
	if(this -> count(target) < 1)
	{
		this -> dynamicBag::insert(target);
	}
}