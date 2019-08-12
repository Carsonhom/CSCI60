#include "node.h"
#include <iostream>
#include <string>
#include <set>
#include <fstream>
using namespace std;

int sequence(int n);

int main()
{
	cout << "Enter the nth number in the sequence: ";
	int input;
	cin >> input;
	cout << sequence(input) << endl;
	return 0;
}

int sequence(int n)
{
	if(n == 0 || n == 1) 
	{
		return 1;
	}
	else
	{
		return (n - 1) + sequence(n - 2);
	}
}

