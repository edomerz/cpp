/****************************************************************************
	q26
AUTHOR: omer ido                                                   
CREATE DATE: 30/03/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __Q26_H__
#define __Q26_H__

#include <iostream> 

class X
{
public:
	X(int n): m_num(n) {}
	operator int() const { return m_num; }
	int GetNum() const { return m_num; }
private:
	int m_num;
};

void Foo(X x)
{
	std::cout<<x.GetNum()<<std::endl;
	std::cout<<x<<std::endl;
}

void Bar(int num)
{
	std::cout<<num<<std::endl;
}



#endif /* ifndef __Q26_H__*/
