/*
 * proxy.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: qwerty
 */

#ifndef PROXY_CPP__
#define PROXY_CPP__

#include "rcstring.h"


namespace ilrd
{
using ilrd::RCString;

class Proxy
{
public:
	Proxy(RCString& rcstring_, size_t pos_);
	Proxy(const Proxy& other_);

	Proxy& operator=(const Proxy& other_);

	//s1[2] = 'a' → oper=(s1[2], 'a') → oper=((oper[](s1, 2)), 'a')
	Proxy& operator=(const char c); //

	// cout<<s[3] // implicit conversion operator
	operator char();

	~Proxy();
private:
	RCString& m_rcstring;
	size_t m_pos;
};

}

#endif /* PROXY_CPP_ */
