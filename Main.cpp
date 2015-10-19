#include "LinkedList.h"
#include "Node.h"
#include "Iterator.h"
#include <iostream>
using namespace std;

int main()
{
	int*x=new int;
	*x = 4;
	LinkedList<int>* a = new LinkedList<int>(3);
	a->Append(x);
	a->Prepend(x);
	Node<int>* temp = new Node<int>();
	temp->set_m_data(a->Extract(3).get_m_data());
	*x = temp->get_m_data();
	a->InsertAfter(4,x);
	a->InsertBefore(3, x);
	Iterator<int> *y;
	y=&a->Begin();
//	(*y)++;
	++(*y);
	LinkedList<int>* b = new LinkedList<int>(*a);

	a->Purge();
	

	//cout << "Hello World" << endl;
	//cout << a->Head()->get_m_next() << endl;
	return 0;
}