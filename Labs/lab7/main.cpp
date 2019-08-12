#include <iostream>
#include <string>
#include <set>
#include <fstream>
using namespace std;

int salary(int n);

int main()
{
	cout << salary(5) << endl;
	return 0;
}

int salary(int n)
{
	if(n == 1)
	{
		return 50;
	} 
	else
	{
		return 5 + 1.1 * salary(n - 1);
	}
}