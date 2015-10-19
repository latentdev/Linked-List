#include "Iterator.h"
template<typename a_type>
Iterator<a_type>::Iterator()
{
	m_node = 0;
}

template<typename a_type>
Iterator<a_type>::Iterator(Node<a_type> x)
{
	m_node = &x;
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
Node<a_type>* Iterator<a_type>::get_m_node()const
{
	return m_node;
}

template<typename a_type>
void Iterator<a_type>::set_m_node(Node<a_type>* x)
{
	m_node = x;
}

template<typename a_type>
Iterator<a_type>& Iterator<a_type>::operator=(Iterator<a_type>& obj)
{
	m_node = obj.get_m_node();
	return *this;
}

template<typename a_type>
Iterator<a_type>& Iterator<a_type>::operator++()
{
	m_node = m_node->get_m_next();
	return *this;
}

template<typename a_type>
Iterator<a_type> Iterator<a_type>::operator++(int in)
{
	//Node<a_type>* point = m_node;
	Iterator<a_type> x(*m_node);
	++(*this);
	return x;
}
