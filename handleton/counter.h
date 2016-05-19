#ifndef __COUNTER_H__
#define __COUNTER_H__

#include <iostream>
#include <stdio.h>

#define __INSTANCE__
#include "handleton.h"

namespace ilrd
{

class Counter
{
public:
	Counter(): m_c(0ul) {}
	~Counter(){}
	
	void Inc();
	void Print();
private:
	size_t m_c;
};



}


#endif // __COUNTER_H__
