#include <iostream>

#include "interface.h"

class Interface2 : public Interface
{
public:
	Interface2()
	{}
	
	virtual ~Interface2()
	{}
	
	virtual void DoSomething()
	{
		std::cout << "implementation 2!!!." << std::endl;
	}
};

REGISTER_INTERFACE("impl2", Interface2);
