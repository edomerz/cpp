
#include "string_m.h"

namespace ilrd
{
// non default Ctor
String::String(const char *str)
{
	Create(m_str, str);
//	size_t len(strlen(str));
//	m_str = new char(len + 1);
//	memcpy(m_str, str, len + 1);

//	std::cout<<"size of str: "<<len<<"\nstr: "<<str<<"\nm_str: "<< m_str<<"\n";
}

String::~String()
{
	delete[] m_str;
}

//CCtor
String::String(const String& other_)
{
	Create(m_str, other_.m_str);
//	size_t len(strlen(other_.m_str));
//	m_str = new char(len + 1);
//	memcpy(m_str, other_.m_str, len + 1);
//	std::cout<<"CCtor\n";
}

String& String::operator=(const String& other_)
{
	if(*this == other_)
	{
		return *this;
	}
	delete[] m_str;
	Create(m_str, other_.m_str);
//	m_str = new char(strlen(other_.m_str) + 1);
//	memcpy(m_str, other_.m_str, (strlen(other_.m_str) + 1));
//	std::cout<<"=: m_str: "<<m_str<<'\n';
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
