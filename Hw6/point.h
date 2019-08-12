#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <string>
#include <math.h>

template <class T>
class point
{
public:
	point();
	point(int dim);
	point(T a[], int dim);
	T getData(int i);
	int getSize();
	point<T> operator =(const point & rhs);
	void operator +=(const point & rhs);
private:
	T data[10];
	int dimension;
};

template<class T>
point<T>::point() : data(), dimension(0)
{
}

template<class T>
point<T>::point(int dim) : data(), dimension(dim)
{
}

template<class T>
point<T>::point(T a[], int dim) : data(), dimension(dim)
{
	for(int i = 0; i < dim; i++)
	{
		data[i] = a[i];
	}
}

template<class T>
T point<T>::getData(int i)
{
	return data[i];
}

template<class T>
int point<T>::getSize()
{
	return dimension;
}

template<class T>
point<T> point<T>::operator =(const point & rhs)
{
	dimension = rhs.dimension;
	for(int i = 0; i < dimension; ++i)
	{
		data[i] = rhs.data[i];
	}
	return (*this);
}

template<class T> 
void point<T>::operator +=(const point & rhs) // Type variable needs to support += and = operator
{
	if(dimension < rhs.dimension)
	{
		dimension = rhs.dimension;
	}
	for(int i = 0; i < dimension; ++i)
	{
		data[i] += rhs.data[i];
	}
}

template<typename T>
point<T> operator +(point<T> lhs, point<T> rhs) // Type variable needs to support += and = operator
{
	point<T> c = lhs;
	c += rhs;
	return c;
}

template<typename T>
bool operator ==(point<T> lhs, point<T> rhs)
{
	if(lhs.getSize() == rhs.getSize())
	{
		for(int i = 0; i < lhs.getSize(); ++i)
		{
			if(lhs.getData(i) != rhs.getData(i))
			{
				return false;
			}
		}
		return true;
	}
	else return false;
}

// template<typename T>
// int operator -(const std::string & lhs, const std::string & rhs)
// {
// 	int c = (int)(lhs.front() - rhs.front()); 
// 	std::cout << "yoit";
// 	return c;
// }

// template<class T>
// double distance(point<T> a, point<T> b)
// {
// 	double dist = 0;
// 	for(int i = 0; i < a.getSize(); ++i)
// 	{
// 		int c = b.getData(i) - a.getData(i);
// 		dist += pow(c, 2);
// 	}
// 	return sqrt(dist);
// }

#endif