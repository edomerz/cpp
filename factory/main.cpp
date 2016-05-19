#include <iostream>

#include "interface.h"

using namespace std;

int main(int argc, char* argv[])
{
	Pinterface if1 = Interface::Create("impl1");
	
	if1->DoSomething();
	
	cout << endl;
	
	Pinterface if2 = Interface::Create("impl2");
	if2->DoSomething();
	cout << endl;
	
	return(0);
}
