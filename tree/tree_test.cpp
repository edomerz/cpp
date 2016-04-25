#include "tree.h"

using namespace ilrd;

int main(int argc, char* argv[], char** envp)
{
	File file1("f1");
	file1.Display();
	
	Component* dir = CreateRepository(".");

	std::cout <<"\n*********************************************************\n\n";
	dir->Display();


	std::cout <<"\n*********************************************************\n\n";

	const Component* ret = FindPath(dir, ".");

	ret->Display();

	std::cout <<"\n*********************************************************\n\n";

	const Component* ret2 = FindPath(dir, "./tmp2");

	ret2->Display();

	std::cout <<"\n*********************************************************\n\n";

	const Component* ret3 = FindPath(dir, "./tmp1");

	ret3->Display();

	delete dir;

	return(0);
}
