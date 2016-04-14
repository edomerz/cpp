#include <cassert>
#include "string_m.h"

namespace ilrd
{
// non default Ctor
String::String(const char *str): m_str(Create(str))
{}

String::~String()
{
	delete[] m_str;
}

//CCtor
String::String(const String& other_): m_str(Create(other_.m_str))
{}

String& String::operator=(const String& other_)
{
	if(this == &other_) // checks for self assignment
	{
		return *this;
	}
	delete[] m_str;
	m_str = Create(other_.m_str);

	return *this;
}

char& String::operator[](size_t pos_)
{
	assert(pos_  < Length());
	return(m_str[pos_]);
}


const char& String::operator[](size_t pos_) const
{
	assert( pos_ < Length());
	return(m_str[pos_]);
}

size_t String::Length() const
{
	return(strlen(m_str));
}

bool operator==(const String& this_, const String& other_)
{
	return(!strcmp(this_.m_str, other_.m_str));
}

std::ostream& operator<<(std::ostream& out, const String& other_)
{
	return(std::cout<<other_.m_str);
}

}
