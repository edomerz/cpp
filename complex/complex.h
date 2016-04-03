/****************************************************************************
	complex
AUTHOR: omer ido                                                   
CREATE DATE: 30/03/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <iostream> 

namespace ilrd
{

class Complex;

// iostream operators overloading
std::istream& operator>>(std::istream& input, Complex& c);
std::ostream& operator<<(std::ostream& output, Complex& c);

//global functions operators
// used as global for symmetry and for input that is a class not our own
bool operator==(const Complex& num1, const Complex& num2_);
bool operator!=(const Complex& num1, const Complex& num2);
Complex operator+(const Complex& num1, const Complex& num2){ return (num1 += num2)}
Complex operator-(const Complex& num1, const Complex& num2){ return(num1 -= num2)}
Complex operator*(const Complex& num1, const Complex& num2);


class Complex
{
	double m_real, m_im;

public:
	Complex(double real_ = 0.0, double img_ = 0.0): m_real(real_), m_im(img_){}

	//using generated functions
	//Complex(double r): re(r), im(0){}
	//Complex(): re(0), im(0){}
	//~Complex(); //dtor
	double GetReal()const
	{
		return m_real;
	}
	void SetReal(double d)
	{
		m_real = d;
	}
	double GetImg() const
	{
		return m_im;
	}
	void GetImg(double d)
	{
		m_im = d;
	}

	Complex& operator+=(const Complex other_){ m_real += other_.m_real, m_im += other_.m_im; return *this;}
	Complex& operator-=(const Complex other_){ m_real -= other_.m_real, m_im -= other_.m_im; return *this;}
	Complex& operator*=(const Complex other_); //defined out of class

};

#endif /* ifndef __COMPLEX_H__*/
