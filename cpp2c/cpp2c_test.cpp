#include "cpp2c.h"
	
int main(int argc, char **argv, char **envp)
{
	Centipede c;
	Foo(c);
	Foo(3).Display();

    FiFi(c);

	Animal *array[] =
	{
		new Centipede(),
		new Squirl(),
		new Centipede()
	};

	for(int i = 0; i < 3; ++i) array[i]->Display();
	for(int i = 0; i < 3; ++i) delete array[i];

	Animal arr2[] =
	{
		Centipede(),
		Squirl(),
		Animal()
	};

	for(int i = 0; i < 3; ++i)
	{
		arr2[i].Display();
	}

	Animal::PrintCount();
	Centipede c2;
	c2.PrintCount();
	
//	Centipede arr3[4];
	Squirl *arr4 = new Squirl[4];
	delete [] arr4;
/*
	LegendaryAnimal *la1 = new LegendaryAnimal();
	LegendaryAnimal *la2 = new LegendaryAnimal(*la1);
	la1->Display();
	la2->Display();
	delete la1;
	la2->Display(); // this crashes. fix the bug!
	delete la2;
*/
	return 0;
}
