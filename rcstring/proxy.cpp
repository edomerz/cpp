/*
 * proxy.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: qwerty
 */

#ifndef PROXY_CPP_
#define PROXY_CPP_

#include "proxy.h"

namespace ilrd
{
using ilrd::RCString;

Proxy::Proxy(RCString& rcstring_, size_t pos_): m_rcstring(rcstring_), m_pos(pos_)
{}

Proxy::Proxy(const Proxy& other_): m_rcstring(other_.m_rcstring), m_pos(other_.m_pos)
{}

Proxy& Proxy::operator =(const Proxy& other_)
{
	m_rcstring = other_.m_rcstring;
	m_pos = other_.m_pos;

	return(*this);
}


Proxy& Proxy::operator=(char c)
{
	m_rcstring.DecRefBuf();
	m_rcstring.SetBuf(new Buffer(*m_rcstring.GetBuf()));

	m_rcstring.GetBuf()->m_string.operator [](m_pos) = c;

	return(*this);
}

Proxy::operator char()
{
	return(m_rcstring.operator [](m_pos));
}

Proxy::~Proxy()
{}


}
#endif /* PROXY_CPP_ */
