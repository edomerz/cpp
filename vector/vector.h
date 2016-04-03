/****************************************************************************
	vector
AUTHOR: omer ido                                                   
CREATE DATE: 29/03/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream> 

enum Color
{
	red,
	blue,
	green
};

class Vector
{
private:
	double *elem; 							// poiter to the elements
	int sz;									// number of elements
public:
	Vector(std::initializer_list<double>lst): elem(new double[lst.size()]), sz(lst.size())
	{
		std::copy(lst.begin(), lst.end(), elem);
	}
	Vector(int s): elem (new double[s]), sz(s) 	// construct a Vector
	{
		if(s < 0)
		{
			std::cout<<"s < 0\n";
			return;
		}
		for(int i = 0; i < s; ++i)
		{
			elem[i] = 0;
		}
	}
	~Vector()
	{
		delete[] elem;
	}
	double& operator[](int i);
	int size();

};

double read_and_sum(int s);


#endif /* ifndef __VECTOR_H__*/
