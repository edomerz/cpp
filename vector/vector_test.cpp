#include "vector.h"
#include <cmath>

double sqrt_num(Vector& v);

int main(void)
{
	
	std::cout<<read_and_sum(3);

	return(0);
}

double sqrt_num(Vector& v)
{
	double sum = 0;
	for(int i = 0; i < v.size(); ++i)
	{
		sum += sqrt(v[i]);
	}

	return sum;
}
