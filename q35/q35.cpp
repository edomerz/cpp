#include "q35.h"
		
void Fifi()
{
	throw BadDog("bad pup");
	cerr << "Fifi() after throw" << endl;
}

void Foo()
{
	Fifi();
	cerr << "Foo() after Fifi()" << endl;
}

void Bar()
{
	Foo();
	cerr << "bar() after Foo()" << endl;
}
