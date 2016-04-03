/****************************************************************************
	new_vector
AUTHOR: omer ido                                                   
CREATE DATE: 30/03/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __NEW_VECTOR_H__
#define __NEW_VECTOR_H__

#include <iostream> 

class Vector
{
private:
	double *elem; 							// poiter to the elements
	int sz;									// number of elements
public:
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
	int size() const;

};

class Container
{
public:
	virtual double& operator[](int) = 0;
	virtual int size() const = 0;
	virtual ~Container() {}
};


class Vector_container: public Container
{
	Vector v;
public:
	Vector_container(int s): v(s){}
	~Vector_container(){}

	double& operator[](int i){ return v[i];}
	int size() const { return v.size();}
};

void use_vec(Container& c)
{
	const int sz = c.size();

	for(int i = 0; i != sz; ++i)
		std::cout<<c[i]<<'\n';
}
#endif /* ifndef __NEW_VECTOR_H__*/
