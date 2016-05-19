#include <iostream>

#include "interface.h"

class Interface1: public Interface
{
public:
	Interface1()
	{}
	
	virtual ~ Interface1()
	{}
	
	virtual void DoSomething()
	{
		std::cout << "implementation 1." << std::endl;
	}
};

REGISTER_INTERFACE("impl1", Interface1);



