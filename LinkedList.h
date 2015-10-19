#pragma once
#include "Node.h"
#include "Iterator.h"
#include "Exception.h"
template<typename a_type>
class LinkedList
{
private:
	Node<a_type>* m_tail;
	Node<a_type>* m_head;
public:
	LinkedList();
	LinkedList(a_type in_data);
	LinkedList(const LinkedList& obj);
	~LinkedList();
	bool isEmpty()const;
	const Node<a_type>& First();
	const Node<a_type>& Last();
	void Prepend(a_type* in);
	void Append(a_type* in);
	void Purge();
	Node<a_type>& Extract(a_type in);
	void InsertAfter(a_type data, a_type* in);
	void InsertBefore(a_type data, a_type* in);
	Iterator<a_type> Begin();
	Iterator<a_type> End();
	Node<a_type>* get_m_head()const;
	Node<a_type>* get_m_tail()const;
	//Node<a_type>* Head();
};

#include "LinkedList.cpp"