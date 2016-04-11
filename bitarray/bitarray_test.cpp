#include <cstdio>

#include "bitarray.h"

using namespace ilrd;

int main(void)
{
	printf("\n[FILE:%s][func:%s][LINE:%d]%s:\n", __FILE__, __func__, __LINE__, "Create1"); /* DEBUG!!! */
	BitArray<1> ba1;
	std::cout << "\nsizeof(ba1): " << sizeof(ba1)<< std::endl;
	
	printf("\n[FILE:%s][func:%s][LINE:%d]%s:\n", __FILE__, __func__, __LINE__, "Create2"); /* DEBUG!!! */
	BitArray<65> ba2;

	std::cout << "\nsizeof(ba2): " << sizeof(ba2)<< std::endl;

//	ba1 = 1;

	return(0);
}
