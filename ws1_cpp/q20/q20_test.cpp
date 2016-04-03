#include <iostream>

#include "q20.h"

/* understand the syntax, use nm, use debugger
   what is "this"
   what is the size of the struct with the functions
   notice the calling order of Ctor and Dtor of local variables
*/

int main()
{
	std::cout << "hello" << std::endl;
	X x1;
	x1.m_a = 1;
	x1.m_b = 2;

	std::cout << x1.m_a << std::endl;
	X x2;
	
	X* px = new X(x2); // dynamic allocation
	
	X x3;
	x3.m_a = 3;
	x3.m_b = 4;
	
	X x4(x1);
	
	x1 = x3;
	x4 = x1;
	delete px;
	px = 0;
	
	X *xp = new X[10];

	delete[] xp;

	Y y1;
	y1.m_x.m_a = 250;
	y1.m_x.m_b = 750;

	Y y2(y1);

	Y y3;
	y3 = y1;
	y2 = y3;

	return 0;
}
