#include "q20.h"

//X::X(): m_a(3), m_b(4) // Implementation of default Ctor
//{
//	std::cout <<'\n' << "this:" << this << "	x default Ctor. m_a:" << m_a << "	m_b:" << m_b << std::endl;
//}
//
//X::X(int a_, int b_): m_a(a_), m_b(b_) // non default Ctor
//{
//	std::cout << '\n' << "this:" << this <<"	x  int Ctor. m_a:" << m_a << "	m_b:" << m_b << std::endl;
//}
//
//X::X(const X& other_): m_a(other_.m_a), m_b(other_.m_b) // CCtor
//{
//	std::cout<< '\n' << "this:"<<this<<"	X copy Ctor. m_a:" <<m_a<<"	m_b:"<<m_b<<std::endl;
//}

X& X::operator = (const X& other_) // assignment operator, return a ref to support שירשור  , need to suppport a = a self assignment
{
	m_a = other_.m_a;
	m_b = other_.m_b;

	std::cout <<'\n' << "this:" << this << "	x assignment operator. m_a:" << m_a << "	m_b:" << m_b << std::endl;

	return *this;
}

//X:: ~X()
//{
//	std::cout << '\n' << "this:" << this << "		x Dtor. m_a:" << m_a << " m_b:" << m_b << std::endl;
//}
		

