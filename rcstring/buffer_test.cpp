/*
 * buffer_test.c
 *
 *  Created on: Apr 7, 2016
 *      Author: qwerty
 */

#include "buffer.h"


using namespace ilrd;
using namespace std;
int main()
{
	Buffer buffer1("abcd");
	cout<<"sizeof(buffer1): "<<sizeof(buffer1)<<endl;
	Buffer buffer2 = "hello";

	cout<<"buffer1.m_string.Length(): "<<buffer1.m_string.Length()<<endl;
	cout<<"buffer2.m_string.Length(): "<<buffer2.m_string.Length()<<endl;

	return(0);
}

