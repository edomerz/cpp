#include "complex.h"
	
int main(void)
{
	complex a(2.3);
	complex b(a);
	
	if(a == b)
		std::cout<<a.real()<<'.'<<a.imag();

	return(0);
}
