
/*
 * rcstring.h
 *
 *  Created on: 06/04/2016
 *      Author: Ricki Yaish
 */


#ifndef __RCSTRING_H__
#define __RCSTRING_H__

#include "string.h"

namespace ilrd
{

class RCString;

std::ostream& operator<<(std::ostream& os, const RCString& string_);
bool operator==(const RCString& this_, const RCString& other_);

class RCString
{
	class Proxy;	//forward declaration
	struct Buffer;
public:

	//constructor + destructor
	/*non-explicit*/RCString(const char *string_= "");
	~RCString();

	//copy behavior
	RCString(const RCString& other_);
	RCString& operator=(const RCString& other_);

	//string position operator
	Proxy operator[](size_t pos_);
	const char& operator[](size_t pos_) const;

	//member functions
	size_t Length() const;

	const String& GetString() const;
	size_t GetRefCount() const;

	void SetString(const String& str_);
	void SetRefCount(size_t ref_count_);


private:

	Buffer *m_buf;

	//input
	friend std::ostream& operator<<(std::ostream& os, const RCString& string_);
	//comparator
	friend bool operator==(const RCString& this_, const RCString& other_);
};

struct RCString::Buffer
{
	//once a buffer has been allocated, it means it has one reference
	/*non-explicit*/Buffer(const char *str_ = "", size_t ref_count_ = 1);
	~Buffer();
	Buffer(const Buffer &other_);

	String m_str;
	size_t m_ref_count;

private:
	Buffer& operator=(const Buffer &other_); //disabled
};

class RCString::Proxy
{
public:
	explicit Proxy(RCString& rcstring_, size_t pos_);
	Proxy& operator=(const Proxy& other_);
	Proxy& operator=(const char c); //support: s1[n] = 'a';
	operator char();//implicit conversion operator to support char c = s1[n]

private:
	RCString& m_the_string;
	size_t m_pos;
};
}

#endif /* ifndef __RCSTRING_H__ */

