#pragma once
#include "Node.h"
template<typename a_type>
class Iterator
{
private:
	Node<a_type>* m_node;
public:
	Iterator();
	Iterator(Node<a_type> x);
	Iterator(const Iterator& obj);
	~Iterator();
	Node<a_type>* get_m_node()const;
	void set_m_node(Node<a_type>*x);
	Iterator<a_type>& operator=(Iterator<a_type>& obj);
	Iterator<a_type>& operator++();
	Iterator<a_type> operator++(int in);


};
#include "Iterator.cpp"
