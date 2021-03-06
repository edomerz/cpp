/****************************************************************************
	string
AUTHOR: omer ido                                                   
CREATE DATE: 03/04/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __STRING_H__
#define __STRING_H__

#include <iostream> 
#include <cstring>


namespace ilrd
{
class String;

std::ostream& operator<<(std::ostream& out, const String& other_);
bool operator==(const String& this_, const String& other_);

class String
{
	friend std::ostream& operator<<(std::ostream& out, const String& str_);
	friend bool operator==(const String& this_, const String& other_);
	char* Create(const char *o_str)
	{
		size_t len = strlen(o_str);
		char* str = new char[len + 1];
		memcpy(str,o_str, len);

		return str;
	}
	char *m_str;

public:
	String(const char *string_ = "");
	~String();

	// copy ctor
	String(const String& other_);
	// Assignment
	String& operator=(const String& other_);

	char& operator[](size_t pos_);
	const char& operator[](size_t pos_) const;

	// member function: length
	size_t Length() const;
};

}
	
#endif /* ifndef __STRING_H__*/
// another implementation for create, mine
//void Create(char *&m_str, const char *o_str)
//{
//	size_t len = strlen(o_str);
//	m_str = new char[len + 1];
//	memcpy(m_str,o_str, len);
//	m_str[len] = '\0';
//}
