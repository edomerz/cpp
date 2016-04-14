#ifndef __RCSTRING_H__
#define __RCSTRING_H__

#include "buffer.h"
#include "proxy.h"

namespace ilrd
{

class RCString;

std::ostream& operator<<(std::ostream& os, const RCString& string_);
bool operator==(const RCString& this_, const RCString& other_);

class RCString
{
private:
	struct Buffer;
	struct Proxy;

public:
	//constructor non-explicit
	RCString(const char *string_="");

	// destructor
	~RCString();

	//copy behavior
	// CCtor
	RCString(const RCString& other_);
	RCString& operator=(const RCString& other_);

	//string position operator
	Proxy operator[](size_t pos_);
	const char& operator[](size_t pos_) const;

	//member functions
	size_t Length() const;

	void SetChar(size_t pos_, const char c);
	char GetChar(size_t pos_);
	size_t GetRefCount() const;

private:
	Buffer *m_buf;

	void IncRefBuf();
	void DecRefBuf();
	void SetBuf(Buffer* buf);
	Buffer* GetBuf();

	//input
	friend std::ostream& operator<<(std::ostream& os, const RCString& rcstring_);
	//comparator
	friend bool operator==(const RCString& this_, const RCString& other_);
};

struct RCString::Buffer
{
	// default ctor
	Buffer(size_t m_ref_count_ = 1, const char* string_= "");
	// cctor
	Buffer(const Buffer& other_);
	// dtor
	~Buffer();

	size_t m_ref_count;
	String m_string;
};

struct RCString::Proxy
{
public:
	// Ctor
	Proxy(RCString& rcstring_, size_t pos_);

	// Assignment operations (overloading)
	Proxy& operator=(const Proxy& other_);

	//s1[2] = 'a' → oper=(s1[2], 'a') → oper=((oper[](s1, 2)), 'a')
	Proxy& operator=(const char c); //

	// implicit conversion operator (cout<<s[3])
	operator char() const;

private:
	RCString& m_rcstring;
	size_t m_pos;
};
}

#endif /* ifndef __RCSTRING_H__ */
