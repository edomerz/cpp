/*
 * buffer.h
 *
 *  Created on: Apr 7, 2016
 *      Author: qwerty
 */

#ifndef BUFFER_H_
#define BUFFER_H_

#include <iostream>
#include "string_m.h"

namespace ilrd
{
class RCString;


struct Buffer
{
	// default ctor
	Buffer(const char* string_= "");
	// non default ctor
	Buffer(size_t m_ref_count_, const char* string_);
	// cctor
	Buffer(const Buffer& other_);
	// oper=
	Buffer& operator=(const Buffer& other_);
	// dtor
	~Buffer();

	size_t m_ref_count;
	String m_string;
};

}
#endif /* BUFFER_H_ */
