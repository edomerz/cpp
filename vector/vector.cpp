#include "vector.h"


//Vector::Vector(int s)
//{
//	if(s < 0)
//	{
//		std::cout<<"length_error";
//	}
//	elem = new double[s];
//	sz = s;
//}

int Vector::size()
{
	return sz;
}

double& Vector::operator[](int i)
{
	if(i < 0 || size() <= i)
	{
		std::cout<<"out of range Vector::operator[]\n";
	}
//	static_assert(i >= 0 || i < size(), "not in range");
	return elem[i];
}

double read_and_sum(int s)
{
	Vector v(s);

	for(int i = 0; i < v.size(); ++i)
	{
		std::cin>>v[i];
	}

	double sum = 0;
	for(int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
	}

	return sum;
}

