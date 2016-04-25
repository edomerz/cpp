#ifndef __CIRC_BUF_H__
#define __CIRC_BUF_H__

#include <iostream>
#include <boost/atomic.hpp>

namespace ilrd
{

class CircBuf
{
public:
	CircBuf(std::size_t capacity_);
	~CircBuf();

	// member functions
	std::size_t Size();
	std::size_t Capacity();
	void Remove();
	void Dequeue(std::size_t& ret);
	void Enqueue(std::size_t& val);
	bool IsEmpty();


private:
	CircBuf(const CircBuf& other_);
	CircBuf& operator=(const CircBuf& other_);

	boost::atomic<size_t> m_atomic_size;

	std::size_t m_capacity;
	std::size_t m_read_i;
	std::size_t m_write_i;
	std::size_t* m_arr;
};

//CircBuf::CircBuf(size_t capacity_):
//		m_capacity(capacity_),
//		m_read_i(0),
//		m_write_i(0),
//		m_arr(new size_t[capacity_])
//{}
//
//CircBuf::~CircBuf()
//{
//	delete[] m_arr;
//}
//
//bool CircBuf::IsEmpty()
//{
//	return(!m_capacity);
//}
//
//size_t CircBuf::Capacity()
//{
//	return(m_capacity);
//}
//
//void CircBuf::Dequeue(size_t& ret)
//{
//	ret = (*m_arr)[m_read_i]
//}
//
//void CircBuf::Remove()
//{
//
//}
//
//void CircBuf::Enqueue(size_t& val)
//{
//	std::cout << "m_write_i before: " << m_write_i << std::endl;
//	(*m_arr)[m_write_i] = val;
//	m_write_i = (m_write_i + 1) % m_capacity;
//	std::cout << "m_write_i after: " << m_write_i << std::endl;
//}

}

#endif // __CIRC_BUF_H__
