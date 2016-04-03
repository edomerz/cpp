//#include <iostream>
//#include "slist.h"
//
//namespace ilrd
//{
////	template<typename T>
////	Slist<T>::Slist():m_head(0)
////	{}
////
////	template <typename T>
////	Slist<T>::~Slist()
////	{
////		Node *tmp = 0;
////		while(m_head)
////		{
////			tmp = m_head->m_next;
////			delete m_head;
////			m_head = tmp;
////		}
////	}
////
////
////	template <typename T>
////	Slist<T>::Node::Node(Node *next_, T data_): m_next(next_), m_data(data_)
////	{
////		std::cout<<"this:"<<this<<"Ctor: m_next: "<<m_next<<" m_data: "<<m_data<<'\n';
////	}
////
////	template <typename T>
////	Slist<T>::Node::Node(const Node& other_): m_next(other_.m_next), m_data(other_,m_data)
////	{
////		std::cout<<"this:"<<this<<"COPY Ctor: m_next: "<<m_next<<" m_data: "<<m_data<<'\n';
////	}
////
////	template <typename T>
////	Slist<T>::Node::~Node(){}
////
////
////
////	template <typename T>
////	void Slist<T>::Node::operator=(const Node& other_)
////	{
////		m_next = other_->m_next;
////		m_data = other_->m_data;
////
////		std::cout<<"this:"<<this<<"operator =: m_next: "<<m_next<<" m_data: "<<m_data<<'\n';
////
////		return(*this);
////	}
//}
