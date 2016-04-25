/*
 * circ_buf_test.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: fullstack
 */

#include "circ_buf.h"

using namespace ilrd;



int main(int argc, char* argv[])
{
	const size_t cap = 10;
	CircBuf buf(cap);

	std::cout << "capacity: " << buf.Capacity() << std::endl;
	std::cout << "is empty: " << buf.IsEmpty() << std::endl;

	for(size_t i = 0; i < cap; ++i)
	{
		buf.Enqueue(i);
	}

	size_t ret_arr[cap];

	std::cout << "capacity: " << buf.Capacity() << std::endl;

	for(size_t i = 0; i < cap; ++i)
	{
		buf.Dequeue(ret_arr[i]);
	}


	return(0);
}
