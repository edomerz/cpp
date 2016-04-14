#include <iostream>
#include <cstring>
#include "string.h"

// using namespace ilrd; // NO! we dont use it, we now define its declarations!

namespace ilrd
{

static void AllocAndCpy(char *& dest_, const char *src_)
{
	dest_ = new char[strlen(src_)+1]; // the +1 is for the null-terminator
	strcpy(dest_, src_);
}

/* another option (pass with: &m_string):
static void Write(char **m_string_, char *other_string_)
{
	*m_string_ = new char[strlen(other_string_)+1]; // the +1 is for the null-terminator
	strcpy(*m_string_, other_string_);
}
* NOTE: it has to be char **dest_, because making it char *dest_ would mean the following:
* 1. we pass m_string (whose type is: char *) to Write
* 2. we inside Write, a TEMP COPY OF M_STRING is created. this temp has an address, that holds
* 	 inside it the address held BY m_string.
* 3. we allocate memory to dest (i.e., m_string), and strcpy into it, which is just ok.
* 4. BUT THEN, when we return from Write, the temp that held dest_ is gone, so: (a) the allocated
*    address is now dangled, it's not returning to the callee (unless we'll add a return value),
*    and (b) the string that was copied into this dangled address is lost in (memory) space.
*/

String::String(const char *string_)
{
	AllocAndCpy(m_string, string_);
}

String::~String()
{
	delete[] m_string;
}

std::ostream& operator<<(std::ostream& os, const String& string_)
{
	std::cout << string_.m_string;
	return os;
}

String::String(const String& other_)
{
	AllocAndCpy(m_string, other_.m_string);
}

String& String::operator=(const String& other_)
{
	if (strcmp(m_string, other_.m_string)) // needed to protect from self-assignment
	{
		delete[] m_string; // destroying the previous string held inside *this
		AllocAndCpy(m_string, other_.m_string);
	}
	return *this;
}

size_t String::Length() const
{
	return (strlen(m_string));
}

char& String::operator[](size_t index_)
{
	return(m_string[index_]);
}

const char& String::operator[](size_t index_) const
{
	return(m_string[index_]);
}

bool operator==(const String& this_, const String& other_)
{
	return (!strcmp(this_.m_string, other_.m_string));
}

}






