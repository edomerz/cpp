/*
 * circ_buf.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: fullstack
 */
#include "circ_buf.h"

namespace ilrd
{

CircBuf::CircBuf(std::size_t capacity_):
		m_atomic_size(0),
		m_capacity(capacity_),
		m_read_i(0),
		m_write_i(0),
		m_arr(new std::size_t[capacity_])
{}

CircBuf::~CircBuf()
{
	delete[] m_arr;
}

std::size_t CircBuf::Size()
{
	return(m_atomic_size);
}

bool CircBuf::IsEmpty()
{
	return(!m_atomic_size);
}

std::size_t CircBuf::Capacity()
{
	return(m_capacity);
}

void CircBuf::Dequeue(std::size_t& ret)
{
	ret = m_arr[m_read_i];
	Remove();
}

void CircBuf::Remove()
{
	m_read_i = (m_read_i + 1) % m_capacity;
}

void CircBuf::Enqueue(std::size_t& val)
{
	std::cout << "m_write_i before: " << m_write_i << std::endl;
	m_arr[m_write_i] = val;
	m_write_i = (m_write_i + 1) % m_capacity;
	std::cout << "m_write_i after: " << m_write_i << std::endl;
}


}
