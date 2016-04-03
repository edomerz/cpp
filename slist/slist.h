/****************************************************************************
	slist
AUTHOR: omer ido                                                   
CREATE DATE: 29/03/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __SLIST_H__
#define __SLIST_H__

#include <iostream>

namespace ilrd
{

template<class T>
class Slist// : public Node<T>
{
public:
	explicit Slist():m_head(0)
	{}
	~Slist()
	{
		Node *tmp = m_head;
		while(m_head)
		{
			tmp = m_head->m_next;
			delete m_head;
			m_head = tmp;
		}
	}

	void Push(const T& data_); // move by reference not value
	T Pop(); // change to void Pop()
	//const T& Peek();
	bool IsEmpty() const;
	size_t Count() const;
	void PrintList() const;

private:
	struct Node
	{
		explicit Node()
		{
			std::cout<<"this:"<<this<<"		Default Ctor: m_next: "<<m_next<<" m_data: "<<m_data<<'\n';
		}
		explicit Node(T data_ = T(), Node *next_ = 0): m_data(data_), m_next(next_)
		{
			std::cout<<"this:"<<this<<"		Ctor: m_next: "<<m_next<<" m_data: "<<m_data<<'\n';
		}
		~Node()
		{}

		Node(const Node& other_): m_next(other_.m_next), m_data(other_.m_data)
		{
			std::cout<<"this:"<<this<<"		COPY Ctor: m_next: "<<m_next<<" m_data: "<<m_data<<'\n';
		}

		Node& operator= (const Node& other_)
		{
			m_next = other_->m_next;
			m_data = other_->m_data;

			std::cout<<"this:"<<this<<"		operator =: m_next: "<<m_next<<" m_data: "<<m_data<<'\n';

			return(this);
		}

		T m_data;  			// change to template
		Node *m_next; 		// ref to the next node
	};

	Node *m_head;
};


//template<typename T>
//Slist<T>::Slist():m_head(0)
//{}
//
//template <typename T>
//Slist<T>::~Slist()
//{
//	Node *tmp = m_head;
//	while(m_head)
//	{
//		tmp = m_head->m_next;
//		delete m_head;
//		m_head = tmp;
//	}
//}
//
//template <typename T>
//Slist<T>::Node::Node()
//{}
//
//template <typename T>
//Slist<T>::Node::Node(T data_, Node *next_):m_data(data_), m_next(next_)
//{
//	std::cout<<"this:"<<this<<"Ctor: m_next: "<<m_next<<" m_data: "<<m_data<<'\n';
//}
//
//template <typename T>
//Slist<T>::Node::Node(const Node& other_): m_next(other_.m_next), m_data(other_,m_data)
//{
//	std::cout<<"this:"<<this<<"COPY Ctor: m_next: "<<m_next<<" m_data: "<<m_data<<'\n';
//}
//
//template <typename T>
//Slist<T>::Node::~Node(){}
//
//
//
//template <typename T>
//Node& Slist<T>::Node::operator=(const Node& other_)
//{
//	m_next = other_->m_next;
//	m_data = other_->m_data;
//
//	std::cout<<"this:"<<this<<"operator =: m_next: "<<m_next<<" m_data: "<<m_data<<'\n';
//
//	return(this);
//}

template<typename T>
void Slist<T>::Push(const T& data_)
{
	Node *new_node = new Node(data_, m_head);
//	new_node->m_data = data_;
//	new_node->m_next = m_head;
	m_head = new_node;

	std::cout<<"head "<<m_head<< '\n';
}

template<typename T>
T Slist<T>::Pop()
{
	if(!m_head)
	{
		std::cout<<"empty list\n";
		return T();
	}
	T ret = m_head->m_data;
	Node *tmp = m_head->m_next;

	delete m_head;
	m_head = tmp;

	return ret;
}

template<typename T>
bool Slist<T>::IsEmpty() const
{
	return(m_head == 0);
}

template <typename T>
size_t Slist<T>::Count() const
{
	Node *iter = m_head;
	size_t count = 0;
	while(iter)
	{
		++count;
		iter = iter->m_next;
	}

	return(count);
}

template<typename T>
void Slist<T>::PrintList() const
{
	Node *iter = m_head;
	while(iter)
	{
		std::cout<<iter->m_data<<"->";
		iter = iter->m_next;
	}
	std::cout<<"END\n";
}

}
#endif /* ifndef __SLIST_H__*/
