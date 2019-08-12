#include "point.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

template <typename T>
T abs(T a, T b);

template <typename T1, typename T2>
int count_exact(T1 a[], T2 size, T1 find);

template <typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high);

int operator -(string lhs, string rhs)
{
	int c = (int)(lhs.front() - rhs.front()); 
	return c;
}

template <class T1, class T2>
T1 frequent(T1 a[], T2 size);

template<class T>
double distance(point<T> a, point<T> b)
{
	double dist = 0;
	for(int i = 0; i < a.getSize(); ++i)
	{
		int c = b.getData(i) - a.getData(i);
		dist += pow(c, 2);
	}
	return sqrt(dist);
}

int main()
{
	int arr[6] = {6, 2, 3, 2, 6, 2};
	int arr2[6] = {7, 3, 4, 3, 7, 3};
	int arrsize = 6;
	int arrfind = 2;
	cout << count_exact(arr, arrsize, arrfind) << endl;

	string str[5] = {"hello", "hello", "hello", "hello", "world"};
	string str2[5] = {"bye", "bye", "bye", "bye", "hello"};
	// char chr[5] = {'h', 'e', 'l' ,'l', 'o'};
	int strsize = 5;
	string strfind = "hello";
	cout << count_exact(str, strsize, strfind) << endl;

	cout << count_range(arr, 6, 2, 4) << endl;

	string strhigh = "world";
	cout << count_range(str, 5, strfind, strfind) << endl;;
	// cout << ("hello" > "world") << endl;


	point<string> p1 = point<string>(str, 5);
	cout << p1.getData(1) << endl;
	cout << p1.getSize() << endl;

	point<string> p2;
	p2 = p1;

	p2 += p1;
	cout << p2.getData(1) << endl;

	point<string> p3 = p2 + p1;
	cout << p3.getData(1) << endl;

	point<string> p4 = p2;

	if(p4 == p2)
	{
		cout << "true" << endl;
	} else cout << "false" << endl;

	string x = "hi";
	string y = "bye";

	point<int> p5 = point<int>(arr, 6);
	point<int> p6 = point<int>(arr2, 6);
	point<string> p7 = point<string>(str2, 5);

	cout << distance(p5, p6) << endl;
	cout << distance(p1, p7) << endl;
	// cout << (x - y) << endl;

	cout << frequent(str, 5) << endl;


	return 0;
}

template <typename T> // Type variable needs to support > and - operators
T abs(T a, T b)
{
	if(a - b > b - a)
	{
		return (a - b);
	}
	else return (b - a);
}

template <typename T1, typename T2>
int count_exact(T1 a[], T2 size, T1 find)
{
	int count = 0;
	for(int i = 0; i < size; ++i)
	{
		if(a[i] == find)
		{
			++count;
		}
	}
	return count;
}

template <typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high)
{
	int count = 0;
	for(int i = 0; i < size; ++i)
	{
		if(a[i] >= low && a[i] <= high)
		{
			++count;
		}
	}
	return count;
}

template <class T1, class T2>
T1 frequent(T1 a[], T2 size) // Type variable needs to support the == operator
{
	map<T1, int> census;
	for(int i = 0; i < size; i++)
	{
		int count = 0;
		for(auto e:census)
		{
			if(e.first == a[i])
			{
				++count;
			}
		}
		if(count > 0)
		{
			++census[a[i]];
		}
		else 
		{
			census[a[i]] = 1;
		}
	}
	int max = 0;
	T1 most;
	for(auto e:census)
	{
		if(e.second > max)
		{
			max = e.second;
			most = e.first;
		}
	}
	return most;
}
