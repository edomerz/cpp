/****************************************************************************
	rcstring
AUTHOR: omer ido                                                   
CREATE DATE: 06/04/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __RCSTRING_H__
#define __RCSTRING_H__

#include <iostream> 


namespace ilrd
{

class rcString;

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
		str[len] = '\0';

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

#endif /* ifndef __RCSTRING_H__*/
