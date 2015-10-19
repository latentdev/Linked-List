#include "Node.h"
template<typename a_type>
Node<a_type>::Node()
{
	m_data = 0;
	m_next = 0;
	m_prev = 0;
}

template<typename a_type>
Node<a_type>::Node(a_type in_data)
{
	m_data = in_data;
	m_next = 0;
	m_prev = 0;
}

template<typename a_type>
Node<a_type>::Node(a_type in_data, Node * in_next, Node * in_prev)
{
	m_data = in_data;
	m_next = in_next;
	m_prev = in_prev;
}

template<typename a_type>
Node<a_type>::Node(const Node & obj)
{
	m_data = obj.get_m_data();
	m_next = obj.get_m_next();
	m_prev = obj.get_m_prev();
}

template<typename a_type>
Node<a_type>::~Node()
{
	if (m_next != 0 && m_prev != 0)
	{
		m_prev->m_next = m_next;
		m_next->m_prev = m_prev;
	}

	else if (m_next == 0 && m_prev != 0)
		m_prev->m_next = 0;

	else if (m_prev == 0 && m_next != 0)
		m_next->m_prev = 0;
}

template<typename a_type>
a_type Node<a_type>::get_m_data()const
{
	return m_data;
}

template<typename a_type>
void Node<a_type>::set_m_data(a_type in_data)
{
	m_data = in_data;
}

template<typename a_type>
Node<a_type>* Node<a_type>::get_m_next()const
{
	return m_next;
}

template<typename a_type>
void Node<a_type>::set_m_next(Node<a_type>* in_next)
{
	m_next = in_next;
}

template<typename a_type>
Node<a_type>* Node<a_type>::get_m_prev()const
{
	return m_prev;
}

template<typename a_type>
void Node<a_type>::set_m_prev(Node<a_type>* in_prev)
{
	m_prev = in_prev;
}
