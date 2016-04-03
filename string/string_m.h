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
//std::istream& operator>>(std::istream& in, const String& other_);

class String
{
	friend std::ostream& operator<<(std::ostream& out, const String& str_);
	friend bool operator==(const String& this_, const String& other_);
	void Create(char *&m_str, const char *o_str)
	{
		size_t len = strlen(o_str);
		m_str = new char[len + 1];
		memcpy(m_str,o_str, len);
		m_str[len] = '\0';
	}
	char *m_str;

public:
	//non explicit because of
	// String s1 = "hello"; // we initialize
	String(const char *string_ = "");
	~String();

	// copy
	String(const String& other_);
	// Assignment
	String& operator=(const String& other_);

	// position
	// does not change the data member itself
	// but what it points to, hence, it is not const
	char& operator[](size_t pos_);
	// overloading. for use with literals
	const char& operator[](size_t pos_) const;
	// the above can be implemented
	// char operator[](size_t pos_) const;

	// member function: length
	size_t Length() const;
};

}
	
#endif /* ifndef __STRING_H__*/
