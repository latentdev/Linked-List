#pragma once
#include "Node.h"
template<typename a_type>
class Iterator
{
private:
	Node<a_type>* m_node;
public:
	Iterator();
	Iterator(Node<a_type> *x);
	Iterator(const Iterator& obj);
	~Iterator();
	Iterator<a_type>& operator=(Iterator<a_type>& obj);
	Iterator<a_type> operator++();


};
#include "Iterator.cpp"
