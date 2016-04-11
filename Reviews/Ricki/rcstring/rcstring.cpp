

/*
 * rcstring.cpp
 *
 *  Created on: 06/04/2016
 *      Author: Ricki Yaish
 */

#include "rcstring.h"

namespace ilrd
{

/*
 * RCSTRING
 */
RCString::RCString(const char *string_): m_buf(new Buffer(string_, 1))
{}

RCString::~RCString()
{
	//calls Buffer's Destructor - there decrease 'ref_count' by one
	if (!(--m_buf->m_ref_count))
	{
		delete m_buf;
	}
}

RCString::RCString(const RCString& other_): m_buf(other_.m_buf)
{
	++m_buf->m_ref_count; //add another reference to string
}

//in assignment operator need to point 'this' buffer to the buffer of 'other_'
RCString& RCString::operator=(const RCString& other_)
{
	//first, delete previous resources, to avoid leaks....
	if (!(--m_buf->m_ref_count))
	{
		delete m_buf;
	}

	m_buf = other_.m_buf;
	++m_buf->m_ref_count; //add another reference to string

	return *this;
}

RCString::Proxy RCString::operator[](size_t pos_)
{
	Proxy ret(*this, pos_);

	return ret;
}

const char& RCString::operator[](size_t pos_) const
{
	return m_buf->m_str[pos_];
}

size_t RCString::Length() const
{
	return m_buf->m_str.Length();
}

const String& RCString::GetString() const
{
	return m_buf->m_str;
}

size_t RCString::GetRefCount() const
{
	return m_buf->m_ref_count;
}

void RCString::SetString(const String& str_)
{
	m_buf->m_str = str_;
}

void RCString::SetRefCount(size_t ref_count_)
{
	m_buf->m_ref_count = ref_count_;
}

std::ostream& operator<<(std::ostream& os, const RCString& rcstring_)
{
	os << rcstring_.m_buf->m_str;
	return os;
}

bool operator==(const RCString& this_, const RCString& other_)
{
	return this_.m_buf->m_str == other_.m_buf->m_str;
}


/*
 * BUFFER
 */
RCString::Buffer::Buffer(const char *str_, size_t ref_count_):
		m_str(str_),
		m_ref_count(ref_count_)
{}

RCString::Buffer::Buffer(const Buffer &other_):
		m_str(other_.m_str),
		m_ref_count(1)
{}

RCString::Buffer::~Buffer()
{}

/*
 * PROXY
 */
RCString::Proxy::Proxy(RCString& rcstring_, size_t pos_):
		m_the_string(rcstring_),
		m_pos(pos_)
{}

RCString::Proxy& RCString::Proxy::operator=(const Proxy& other_)
{
	*this = other_.m_the_string.GetString()[m_pos];
	return *this;
}

RCString::Proxy& RCString::Proxy::operator=(const char c)
{
	size_t ref_count = m_the_string.GetRefCount();
	if (ref_count > 1)
	{
		m_the_string.SetRefCount(--ref_count);
		m_the_string.m_buf = new Buffer(*m_the_string.m_buf);
	}

	m_the_string.GetString()[m_pos] = c;

	return *this;
}

RCString::Proxy::operator char()
{
	return m_the_string[m_pos];
}

}
