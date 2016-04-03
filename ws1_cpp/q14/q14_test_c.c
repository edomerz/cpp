#include <stdio.h>

const int i = 3; /* here, u get a segmentation fault, u cant change the value of i */
/*int j;*/
int main(void)
{
	/* const int i = 3; here, c programmer can bypass the const */

	int *ip = (int*)&i;
	*ip = 5;

	printf("%d  %d\n", i, *ip);


	return(0);
}
