#include "Driver.h"
#include "LinkedList.h"
#include "Node.h"
#include "Iterator.h"
#include <iostream>
using namespace std;

template<typename a_type>
void DisplayList(LinkedList<a_type>*x);

void Driver()
{
	int*x = new int;
	*x = 4;
	cout << "creating new linked linked list with one node holding the value 3" << endl;
	LinkedList<int>* a = new LinkedList<int>(3);
	DisplayList<int>(a);
	cout << "appending 4" << endl;
	a->Append(x);
	DisplayList<int>(a);
	cout << "prepending 4" << endl;
	a->Prepend(x);
	DisplayList<int>(a);
	Node<int>* temp = new Node<int>();
	cout << "extracting 3 from the list and storing in temp" << endl;
	temp->set_m_data(a->Extract(3).get_m_data());
	DisplayList<int>(a);
	*x = temp->get_m_data();
	cout << "placing back in list after 4" << endl;
	a->InsertAfter(4, x);
	DisplayList<int>(a);
	cout << "placing 3 into list before 3" << endl;
	a->InsertBefore(3, x);
	DisplayList<int>(a);
	Iterator<int> *y;
	cout << "creating new iterator and pointing it at the head of list" << endl;
	y = &(a->Begin());
	cout << y->get_m_node()->get_m_data() << endl;
	cout << "post incrementing iterator" << endl;
	(*y)++;
	cout << y->get_m_node()->get_m_data() << endl;
	cout << "pre incrementing iterator" << endl;
	++(*y);
	cout << y->get_m_node()->get_m_data() << endl;
	cout << "post decrementing iterator" << endl;
	(*y)--;
	cout << y->get_m_node()->get_m_data() << endl;
	cout << "pre decrementing iterator" << endl;
	--(*y);
	cout << y->get_m_node()->get_m_data() << endl;
	cout << "creating new linked list b with our first linked list" << endl;
	LinkedList<int>* b = new LinkedList<int>(*a);
	DisplayList<int>(b);
	cout << "purging a" << endl;
	a->Purge();
}

/******************************************************
*   Purpose:  displays content of list

*         Entry:  passed in a linked list

*         Exit: walks through list outputting the data in each node to the console
*******************************************************/
template<typename a_type>
void DisplayList(LinkedList<a_type>*x)
{
	Iterator<a_type>*m = new Iterator<a_type>(x->Begin());
	while (m->get_m_node()->get_m_next()!=0)
	{
		cout << m->get_m_node()->get_m_data();
		(*m)++;
	}
	cout << m->get_m_node()->get_m_data() << endl;
}