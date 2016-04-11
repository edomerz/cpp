#include "q10416.h"
#include <assert.h>
#include <cstring>

namespace ilrd
{
char* CreateString(const char* str)
{
	assert(str);
	size_t len = strlen(str) + 1;
	char* ret = new char[len];
	memcpy(ret, str, len);

	return(ret);
}

String::String(const char* str): m_str(CreateString(str))
{}
String::~String()
{
	delete[] m_str;
}
String::String(const String& other_): m_str(CreateString(other_.m_str))
{}

String& String::operator=(const String& other_)
{
	assert(other_.m_str);
	char* tmp = CreateString(other_.m_str);
	this->~String();
	m_str = tmp;

	return(*this);
}
const char& String::operator[](size_t index)
{
	assert(index < strlen(m_str));
	return(m_str[index]);
}

}//end namespace ilrd
		

