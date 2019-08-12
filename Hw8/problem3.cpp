#include "node.h"
#include <iostream>
#include <string>
#include <set>
#include <fstream>
using namespace std;

void reverse(int a[], int first, int last);

int main()
{
	cout << "Array" << endl;
	int a[6];
	for(int i = 0; i < 6; ++i)
	{
		a[i] = rand() % 10;
		cout << a[i] << endl;
	}
	reverse(a, 0, 5);
	cout << "Array reverse" << endl;
	for(int j = 0; j < 6; ++j)
	{
		cout << a[j] << endl;
	}

	return 0;
}

void reverse(int a[], int first, int last)
{
	if(last - first == 2 || last - first == 1)
	{
		int f = a[first];
		a[first] = a[last];
		a[last] = f;
		return;
	}
	else
	{
		int f = a[first];
		a[first] = a[last];
		a[last] = f;
		return reverse(a, first + 1, last - 1);
	}
}
