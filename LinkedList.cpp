#include "LinkedList.h"
template<typename a_type>
LinkedList<a_type>::LinkedList()
{
	m_head = new Node<a_type>();
	m_tail = m_head;
}

template<typename a_type>
LinkedList<a_type>::LinkedList(a_type in_data)
{
	m_head = new Node<a_type>(in_data);
	m_tail = m_head;
}

template<typename a_type>
LinkedList<a_type>::LinkedList(const LinkedList & obj)
{

}

template<typename a_type>
LinkedList<a_type>::~LinkedList()
{
	Purge();
}

template<typename a_type>
bool LinkedList<a_type>::isEmpty()
{
	if (m_head == 0)
		return true;
	else
		return false;
}

template<typename a_type>
void LinkedList<a_type>::Prepend(a_type * in)
{
	Node<a_type>* x = new Node<a_type>(*in,m_head,0);
	m_head->set_m_prev(x);
	m_head = x;
}


template<typename a_type>
void LinkedList<a_type>::Append(a_type * in)
{
	Node<a_type>* x = new Node<a_type>(*in,0,m_tail);
	m_head->set_m_next(x);
	m_tail = x;
}

template<typename a_type>
void LinkedList<a_type>::Purge()
{
	Node<a_type>* point = m_tail;
	Node<a_type>* temp = point->get_m_prev();
	while (temp != 0)
	{
		temp = point->get_m_prev();
		delete point;
		point = temp;
	}
	m_head = 0;
	m_tail = 0;
}

template<typename a_type>
Node<a_type>& LinkedList<a_type>::Extract(a_type in)
{
	Node<a_type>*point = m_head;
	if (isEmpty() == true)
	{
		throw Exception("List is empty");
		Node<a_type> x = 0;
		return x;
	}
	
	else if (m_head->get_m_data() == in)
	{
		point = m_head;
		m_head->get_m_next()->set_m_prev(0);
		m_head = m_head->get_m_next();
		return *point;
	}
	Node<a_type>*temp = m_head->get_m_prev();
	while (point != 0 && point->get_m_data() != in)
	{
		temp = point;
		point = point->get_m_next();
	}

	if (point == 0)
		throw Exception("Node not found");
	else
	{
		if (point->get_m_next() != 0)
		{
			point->get_m_prev()->set_m_next(point->get_m_next());
			point->get_m_next()->set_m_prev(point->get_m_prev());
			return *point;
		}
		else
		{
			m_tail = point->get_m_prev();
			m_tail->set_m_next(0);
			return *point;
		}

	}
		
}

template<typename a_type>
void LinkedList<a_type>::InsertAfter(a_type data, a_type * in)
{
	Node<a_type>* point = m_head;
	while (point != 0 && point->get_m_data() != data)
		point = point->get_m_next();
	if (point != 0)
	{
		if (point->get_m_next() != 0)
		{
			Node<a_type>* x = new Node<a_type>(*in, point->get_m_next(), point);
			point->get_m_next()->set_m_prev(x);
			point->set_m_next(x);
		}
		else
		{
			Node<a_type>* x = new Node<a_type>(*in, 0, point);
			point->set_m_next(x);
		}
			
		
	}
	else throw Exception("Node does not exist");

}

template<typename a_type>
void LinkedList<a_type>::InsertBefore(a_type data, a_type * in)
{
	if (m_head == 0)
		throw Exception("List is empty");
	else if (m_head->get_m_data() == data)
	{
		Node<a_type>* x = new Node<a_type>(*in, m_head->get_m_next(), m_head);
		m_head->get_m_next()->set_m_prev(x);
		m_head->set_m_next(x);
	}
	else
	{
		Node<a_type>* point = m_head;
		Node<a_type>* prev = 0;
		while (point != 0 && point->get_m_data() != data)
		{
			prev = point;
			point = point->get_m_next();
		}
		if (point != 0 && point->get_m_next() != 0)
		{
			Node<a_type>* x = new Node<a_type>(*in, point, prev);
			prev->set_m_next(x);
			point->set_m_prev(x);
		}
		else
			throw Exception("Node does not exist");

	}
}

template<typename a_type>
Iterator<a_type> LinkedList<a_type>::Begin()
{
	Iterator<a_type>* x = new Iterator<a_type>(m_head);
	return *x;
}

/*template<typename a_type>
Node<a_type> * LinkedList<a_type>::Head()
{
	return m_head;
}*/