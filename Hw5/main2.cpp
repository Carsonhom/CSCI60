#include <iostream>
#include "dynamicBag.h"
#include "dUset.h"
#include "dSet.h"
using namespace std;

int main()
{
	int arr[5] = {6, 4, 5, 3, 3};
	cout << "Base array: 6, 4, 5, 3, 3" << endl;
	dUset a = dUset();
	dUset b = dUset(arr, 5);
	cout << "Before inserting two 1s into dUset: " << b;
	b.insert(1);
	b.insert(1);
	cout << "Before inserting two 1s into dUset: " << b;
	dSet c = dSet();

	dSet d = dSet(arr, 5);
	cout << "Before inserting two 1s into dSet: " << d;
	d.insert(1);
	d.insert(1);
	cout << "After inserting two 1s into dSet: " << d;
	return 0;
}