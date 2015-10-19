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
	
	if (obj.isEmpty() != true)
	{
		m_head = new Node<a_type>(obj.get_m_head()->get_m_data());
		for (Node<a_type>* p1 = obj.get_m_head(), *p2 = m_head; p1->get_m_next()!=0; p1 = p1->get_m_next(), p2 = p2->get_m_next())
		{
			p2->set_m_next(new Node<a_type>(p1->get_m_next()->get_m_data(),0,p2));
				m_tail = p2->get_m_next();
		}

	}
}

template<typename a_type>
LinkedList<a_type>::~LinkedList()
{
	Purge();
}

template<typename a_type>
bool LinkedList<a_type>::isEmpty()const
{
	if (m_head == 0)
		return true;
	else
		return false;
}

template<typename a_type>
const Node<a_type>& LinkedList<a_type>::First()
{
	return m_head;
}

template<typename a_type>
const Node<a_type>& LinkedList<a_type>::Last()
{
	return m_tail;
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
	return Iterator<a_type> (*m_head);
}

template<typename a_type>
Iterator<a_type> LinkedList<a_type>::End()
{
	return Iterator<a_type>(*m_tail);
}

template<typename a_type>
Node<a_type>* LinkedList<a_type>::get_m_head()const
{
	return m_head;
}

template<typename a_type>
Node<a_type>* LinkedList<a_type>::get_m_tail()const
{
	return m_tail;
}


/*template<typename a_type>
Node<a_type> * LinkedList<a_type>::Head()
{
	return m_head;
}*/