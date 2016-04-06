/****************************************************************************
	q28
AUTHOR: omer ido                                                   
CREATE DATE: 04/04/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __Q28_H__
#define __Q28_H__

#include <iostream> 

using namespace std;

class B
{
public:
	B(int a_ = 8):m_a(a_){cout<<"B::Ctor"<<endl;}
	virtual ~B(){cout<<"B::Dtor"<<endl;}

	virtual void Print1(){cout <<"B::Print1 B::m_a = "<<m_a<<endl;}
	virtual void Print2(){cout <<"B::Print2: "<<m_a<<endl;}
	virtual void Print3(){cout <<"B::Print3: "<<m_a<<endl;}

private:
	int m_a;
};

class X: public B
{
public:
	X():m_b(0){cout<<"X::Ctor"<<endl;}
	~X(){cout<<"X::Dtor"<<endl;}

	void Print1()
	{
		cout<<"X::Print1 X::m_b = "<<m_b<<endl;
		B::Print1();
		cout<<"X::print1 end\n"<<endl;
	}
	void Print2()
	{
		cout << "X::Print2" << endl;
	}

private:
	int m_b;
};

#endif /* ifndef __Q28_H__*/
