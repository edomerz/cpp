/*
 * buffer.c
 *
 *  Created on: Apr 7, 2016
 *      Author: qwerty
 */
#include "buffer.h"

namespace ilrd
{


Buffer::Buffer(const char* string_): m_ref_count(1), m_string(string_)
{}

Buffer::Buffer(size_t m_ref_count_, const char* string_)
	:m_ref_count(m_ref_count_), m_string(string_)
{}

Buffer::Buffer(const Buffer& other_)
	:m_ref_count(other_.m_ref_count), m_string(other_.m_string)
{}

Buffer& Buffer::operator=(const Buffer& other_)
{
	m_ref_count = other_.m_ref_count;
	m_string = other_.m_string;

	return(*this);
}

Buffer::~Buffer()
{}


}
