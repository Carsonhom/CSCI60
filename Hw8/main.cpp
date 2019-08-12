#include "node.h"
#include <iostream>
#include <string>
#include <set>
#include <fstream>
using namespace std;

int sequence(int n);

void list_clear(node * & head_ptr, node * & tail_ptr);

void reverse(int a[], int first, int last);

void list_reverse(node * & head_ptr, node * & tail_ptr);

int main()
{
	cout << "Enter the nth number in the sequence: ";
	int input;
	cin >> input;
	cout << sequence(input) << endl;

	node *head = new node(1, nullptr);
	node *tail(head);
	node *temp;
	temp = new node(2, nullptr);
	tail->set_link(temp);
	tail = temp;
	temp = new node(3, nullptr);
	tail->set_link(temp);
	tail = temp;
	temp = new node(4, nullptr);
	tail->set_link(temp);
	tail = temp;
	temp = new node(5, nullptr);
	tail->set_link(temp);
	tail = temp;
	temp = new node(6, nullptr);
	tail->set_link(temp);
	tail = temp;
	temp = new node(7, nullptr);
	tail->set_link(temp);
	tail = temp;

	cout << "Node: " << endl;
	for (node*p = head; p != nullptr; p = p->link()) 
	{
		cout << p -> data() << endl;
	}

	list_reverse(head, tail);
	cout << "Node after reverse: " << endl;

	for (node*p = head; p != nullptr; p = p->link()) 
	{
		cout << p -> data() << endl;
	}

	// list_clear(head, tail);

	// for (node*p = head; p != nullptr; p = p->link()) 
	// {
	// 	cout << p -> data() << endl;
	// }

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

void list_clear(node * & head_ptr, node * & tail_ptr)
{
	node * nhead;
	for (node * p = head_ptr; p != nullptr; p = p -> link())
	{
		if(p == nullptr)
		{
			return;
		}
		else if(p == tail_ptr)
		{
			nhead = head_ptr;
			tail_ptr = nullptr;
			head_ptr = nullptr;
			delete nhead;
			return;
		}
		else 
		{
			nhead = head_ptr;
			head_ptr = head_ptr -> link();
			delete nhead;
		}
	}
}

void swap(int a[], int first, int last)
{
	int f = a[first];
	a[first] = a[last];
	a[last] = f;
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

void list_reverse(node * & head_ptr, node * & tail_ptr)
{
	int count = 0;
	for(node * p = head_ptr; p != nullptr; p = p -> link())
	{
		++count;
	}
	int arr[count];
	int pos = 0;
	for(node * q = head_ptr; q != nullptr; q = q -> link())
	{
		arr[pos] = q -> data();
		++pos;
	}
	reverse(arr, 0, count - 1);
	int pos2 = 0;
	for(node * r = head_ptr; r != nullptr; r = r -> link())
	{
		r -> set_data(arr[pos2]);
		++pos2;
	}
}