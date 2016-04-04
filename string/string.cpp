
#include "string_m.h"

namespace ilrd
{
// non default Ctor
String::String(const char *str)
{
	Create(m_str, str);
}

String::~String()
{
	delete[] m_str;
}

//CCtor
String::String(const String& other_)
{
	Create(m_str, other_.m_str);
}

String& String::operator=(const String& other_)
{
	if(*this == other_)
	{
		return *this;
	}
	delete[] m_str;
	Create(m_str, other_.m_str);

	return *this;
}

char& String::operator[](size_t pos_)
{
	return(m_str[pos_]);
}

const char& String::operator[](size_t pos_) const
{
	return(m_str[pos_]);
}

size_t ilrd::String::Length() const
{
	return(strlen(m_str));
}

bool operator==(const String& this_, const String& other_)
{
	return(strcmp(this_.m_str, other_.m_str) == 0);
}

std::ostream& operator<<(std::ostream& out, const String& other_)
{
	return(std::cout<<other_.m_str);
}

}
