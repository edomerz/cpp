#include "tree.h"

using namespace ilrd;

int main(int argc, char* argv[], char** envp)
{
	File file1("f1");
	file1.Display();
	
	Component* dir = CreateRepository(".");

	std::cout <<"\n*********************************************************\n\n";
	dir->Display(0);


	delete dir;

	return(0);
}
