#include "node.h"
#include <iostream>
#include <string>
#include <set>
#include <fstream>
using namespace std;

void reverse(int a[], int first, int last);

void list_reverse(node * & head_ptr, node * & tail_ptr);

int main()
{
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

	return 0;
}

