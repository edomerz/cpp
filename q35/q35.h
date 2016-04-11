/****************************************************************************
	q35
AUTHOR: omer ido                                                   
CREATE DATE: 10/04/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __Q35_H__
#define __Q35_H__

#include <iostream>  // runtime_error
#include <stdexcept>
#include <cstdlib>

using namespace std;

struct BadDog: public runtime_error
{
	BadDog(const string& s_ = "This is a bad dog"): runtime_error(s_)
	{}
};

void Fifi();


void Foo();


void Bar();

#endif /* ifndef __Q35_H__*/
