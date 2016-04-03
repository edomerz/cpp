#include "q24.h"
	
int main(void)
{
	X x1(7, -55);
	X x2(x1);

	x1.Inc();
	x1.Inc();

	x2.Dec();
	
	return(0);
}
