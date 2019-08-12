#include "dSet.h"
#include <iostream>

dSet::dSet() 
{
	dUset();
}

dSet::dSet(int a[], int s)
{
	dUset();
	for(size_type i = 0; i < s; ++i)
	{
		int min = i;
		for(size_type j = i; j < s; ++j)
		{
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
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

void dSet::insert(int target)
{
	if(this -> count(target) < 1)
	{
		// int pos;
		// for(int i = 0; i < this -> size(); ++i)
		// {
		// 	if(i == 0 && target < (*this)[i])
		// 	{
		// 		pos = 0;
		// 	}
		// 	else if(i == (this -> size() - 1) && target > (*this)[i])
		// 	{
		// 		pos = this -> size();
		// 	}
		// 	else if(target > (*this)[])
		// }



		int arr[this -> size() + 1];
		for(size_type i = 0; i < this -> size(); ++i)
		{
			arr[i] = (*this)[i];
			// std::cout << (*this)[i];
		}
		arr[this -> size()] = target;
		dSet dnew = dSet(arr, this -> size() + 1);
		(*this) = dnew;
		// std::cout << arr[this -> size()];
		// this -> dynamicBag::insert(target);
		// for(int i = 0; i < (this -> size() + 1); ++i)
		// {
		// 	int min = i;
		// 	for(int j = i; j < (this -> size() + 1); ++j)
		// 	{
		// 		if(arr[j] < arr[min])
		// 		{
		// 			min = j;
		// 		}
		// 	}
		// 	int temp = arr[i];
		// 	arr[i] = arr[min];
		// 	arr[min] = temp;
		// 	std::cout << temp;
		// }
		// for(int i = 0; i < this -> size() + 1; ++i)
		// {
		// 		this -> dynamicBag::insert(arr[i]);
		// }
	}
}