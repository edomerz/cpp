#ifndef __RCSTRING_H__
#define __RCSTRING_H__

#include "buffer.h"
#include "proxy.h"

namespace ilrd
{

class RCString;
struct Buffer;
class Proxy;

std::ostream& operator<<(std::ostream& os, const RCString& string_);
bool operator==(const RCString& this_, const RCString& other_);

class RCString
{
public:
	//constructor non-explicit
	RCString(const char *string_="");

	// destructor
	~RCString();

	//copy behavior
	RCString(const RCString& other_);
	RCString& operator=(const RCString& other_);

	//string position operator
	Proxy operator[](size_t pos_);
	const char& operator[](size_t pos_) const;

	//member functions
	size_t Length() const;
	void IncRefBuf()
	{
		++m_buf->m_ref_count;
	}
	void DecRefBuf()
	{
		--m_buf->m_ref_count;
	}

	void SetBuf(Buffer* buf);
	Buffer* GetBuf();

private:
	Buffer *m_buf;

	//input
	friend std::ostream& operator<<(std::ostream& os, const RCString& rcstring_);
	//comparator
	friend bool operator==(const RCString& this_, const RCString& other_);
};

}

#endif /* ifndef __RCSTRING_H__ */
