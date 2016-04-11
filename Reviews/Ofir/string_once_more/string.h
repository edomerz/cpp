#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>

namespace ilrd
{

class String;
std::ostream& operator<<(std::ostream& os, const String& string_);
bool operator==(const String& this_, const String& other_);

class String
{
public:
	//constractor + destractor
	/*non-explicit*/String(const char *string_="");
	~String();

	//copy behavior
	String(const String& other_);
	String& operator=(const String& other_);

	//string position operator
	char& operator[](size_t pos_);
	const char& operator[](size_t pos_) const;


	size_t Length() const;

private:
	char *m_string;

	//output
	friend std::ostream& operator<<(std::ostream& os, const String& string_);
	//comperator
	friend bool operator==(const String& this_, const String& other_);

};
}

#endif /* __STRING_H__  */




