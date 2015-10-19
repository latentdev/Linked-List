#include "Iterator.h"
template<typename a_type>
Iterator<a_type>::Iterator()
{
	m_node = 0;
}

template<typename a_type>
Iterator<a_type>::Iterator(Node<a_type> *x)
{
	m_node = x;
}

template<typename a_type>
Iterator<a_type>::Iterator(const Iterator & obj)
{
}

template<typename a_type>
Iterator<a_type>::~Iterator()
{
}

template<typename a_type>
Iterator<a_type>& Iterator<a_type>::operator=(Iterator<a_type>& obj)
{
	return obj;
}

template<typename a_type>
Iterator<a_type> Iterator<a_type>::operator++()
{
	if (m_node->get_m_next()!=0)
	m_node = m_node->get_m_next();
	return this;
	else return 0;
}
