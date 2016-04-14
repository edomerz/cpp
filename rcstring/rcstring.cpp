#include "rcstring.h"

namespace ilrd
{
// ******************************** RCString ***********************************
//constructor non-explicit
RCString::RCString(const char *string_): m_buf(new Buffer(1, string_))
{}

// destructor
RCString::~RCString()
{
	if(--(m_buf->m_ref_count) == 0)
	{
		delete m_buf;
	}
}

//copy behavior - when copied inc the ref counter
RCString::RCString(const RCString& other_): m_buf(other_.m_buf)
{
	IncRefBuf();
}

RCString& RCString::operator=(const RCString& other_)
{
	++other_.m_buf->m_ref_count; // first inc other, handles self assignment with only 1 owner
	this->~RCString(); // avoid mem leaks

	m_buf = other_.m_buf;
	
	return *this;
}

//string position operator
RCString::Proxy RCString::operator[](size_t pos_)
{
	return(Proxy(*this, pos_)); // create a temp and send it
}
const char& RCString::operator[](size_t pos_) const
{
	return(m_buf->m_string[pos_]);
}

// RCString member functions
void RCString::IncRefBuf()
{
	++m_buf->m_ref_count;
}
void RCString::DecRefBuf()
{
	--m_buf->m_ref_count;
}
size_t RCString::Length() const
{
	return(m_buf->m_string.Length());
}

void RCString::SetChar(size_t pos_, const char c )
{
	m_buf->m_string.m_str[pos_] = c;
}

char RCString::GetChar(size_t pos_)
{
	return(m_buf->m_string.m_str[pos_]);
}

size_t RCString::GetRefCount() const
{
	return(m_buf->m_ref_count);
}
void RCString::SetChar(size_t pos_, const char c)
{
	m_buf->m_string[pos_] = c;
}

char RCString::GetChar(size_t pos_)
{
	return(m_buf->m_string[pos_]);
}



//input
std::ostream& operator<<(std::ostream& os, const RCString& rcstring_)
{
	return(os<<rcstring_.m_buf->m_string);
}
//comparator - compare between string, using oper== in String class
bool operator==(const RCString& this_, const RCString& other_)
{
	return(this_.m_buf->m_string == other_.m_buf->m_string);
}
// ****************************** Buffer **************************************
RCString::Buffer::Buffer(size_t m_ref_count_, const char* string_)
	:m_ref_count(m_ref_count_), m_string(string_)
{}

RCString::Buffer::Buffer(const Buffer& other_)
	:m_ref_count(1),  m_string(other_.m_string)
{}

RCString::Buffer& RCString::Buffer::operator=(const Buffer& other_)
{
	m_ref_count = other_.m_ref_count;
	m_string = other_.m_string;

	return(*this);
}

RCString::Buffer::~Buffer()
{}
// ****************************** Proxy **************************************
RCString::Proxy::Proxy(RCString& rcstring_, size_t pos_): m_rcstring(rcstring_), m_pos(pos_)
{}

RCString::Proxy::Proxy(const Proxy& other_): m_rcstring(other_.m_rcstring), m_pos(other_.m_pos)
{}

RCString::Proxy& RCString::Proxy::operator=(const char c)
{
	m_buf->m_string.operator [](m_pos) = c;
	return(*this);
//	RCString::SetChar(m_pos, c);
//	m_rcstring.DecRefBuf();
//
//	m_rcstring.m_buf = new Buffer(*m_rcstring.m_buf);
//
//	m_rcstring.GetStr()[m_pos] = c;

	return(*this);
}

RCString::Proxy& RCString::Proxy::operator=(const Proxy& other_)
{
	return(*this = char(other_));
}


RCString::Proxy::operator char()
{
	return(m_rcstring.m_buf->m_string[m_pos]);
}

RCString::Proxy::~Proxy()
{}
}
