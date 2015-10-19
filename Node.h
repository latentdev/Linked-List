#pragma once
template <typename a_type>
class Node
{
private:
	a_type m_data;
	Node* m_next;
	Node* m_prev;
public:
	Node();
	Node(a_type in_data);
	Node(a_type in_data, Node * in_next, Node * in_prev);
	Node(const Node& obj);
	~Node();
	a_type get_m_data()const;
	void set_m_data(a_type in_data);
	Node<a_type>* get_m_next()const;
	void set_m_next(Node<a_type>* in_next);
	Node<a_type>* get_m_prev()const;
	void set_m_prev(Node* in_prev);

};
#include "Node.cpp"