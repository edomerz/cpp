#include <iostream>
#include <cstdlib>

#include "counter.h"
#include "hangleton.h"

using namespace ilrd;

int main(int argc, char *argv[])
{
	Singleton<Counter>::GetInst().Inc();
	Singleton<Counter>::GetInst().Print();
	
	return(0);
}
