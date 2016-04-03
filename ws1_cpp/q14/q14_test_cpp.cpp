#include <stdio.h>

	
	const int i = 3; /* u cant chage the value if i through ip , segmentation fault */
int main(void)
{
	/* const int i = 3;*/

	int *ip = (int*)&i;
	*ip = 5;

	printf("%d  %d\n", i, *ip);

	
	return(0);
}
