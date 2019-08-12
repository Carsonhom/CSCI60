#include "bag.h"
#include <iostream>

using namespace std;

int main() {

	bag<int> a = bag<int>();
	a.insert(5);
	a.insert(4);
	a.insert(3);
	a.insert(2);
	a.insert(1);
	for(auto e:a)
	{
		cout << e << endl;
	}

	bag<int>::iterator i;
	for(i = a.begin(); i != a.end(); i++)
	{
		cout << *i << endl;
	}
	
	return 0;
}