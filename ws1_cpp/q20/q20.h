/****************************************************************************
	q20
AUTHOR: omer ido                                                   
CREATE DATE: 28/03/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __Q20_H__
#define __Q20_H__

#include <iostream> 

struct X
{
// members functions
//	explicit X(); 						//init function without parameters is called default constructor
//	explicit X(int a_, int b_ = 8); 	// regular Ctor
//	X(const X& other_);				 	//copy Ctor, init function called copy constructor or CCtor

//	~X(); 								// deintialization function, named destructor
	
	X& operator = (const X& other_); 	// assignment operator

	// data members
	int m_a;
	int m_b;
};

struct Y
{
	X m_x;
	int m_i;
};

#endif /* ifndef __Q20_H__*/
