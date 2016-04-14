
#include <iostream>
using namespace std;
	
class Animal
{
public:
	Animal(): m_id(++s_count)
	{ 
		cout << "Animal::Ctor()"  << m_id << endl; 
	}

	virtual ~Animal()
	{
		--s_count;
		cout << "Animal::Dtor()" << m_id  << endl;
	}

	Animal(const Animal &other) : m_id(++s_count)
	{ 
		cout << "Animal::CCtor() "  << m_id << endl; 
	}

	virtual void Display() 
	{ 
		cout << "Animal::Display() : " << m_id << endl; 
	}

	static void PrintCount()
	{
		cout << "s_count: " << s_count << endl;
	}
protected:
	int GetID()
	{
		return m_id;
	}

private:
	static int s_count;
	int m_id;
	Animal &operator=(const Animal &); // disabled
};

int Animal::s_count = 0;


class Centipede: public Animal
{
public:
	Centipede(): m_numLegs(46)
	{ 
		cout << "Centipede::Ctor()" << endl; 
	}
	Centipede(const Centipede &other ): Animal(other)a, m_numLegs(other.m_numLegs)
	{ 
		cout << "Centipede::CCtor()" << endl; 
	}
	~Centipede()
	{
		cout << "Centipede::dtor()" << endl;
	}
	void Display()
	{
		cout << "Centipede::Display() ID:"<<GetID()<<"  num legs:" << m_numLegs << endl;
	}
	virtual void BuyShues()
	{
		cout << "Centipede::BuyShues() ID:"<<GetID() << endl;
	}

private:
	int m_numLegs;
};

class Squirl: public Animal
{
public:
	Squirl()
	{
		cout << "Squirl::Ctor()" << endl;
	}
	Squirl(const Squirl &other ): Animal(other)
	{
		cout << "Squirl::CCtor()" << endl;
	}
	~Squirl()
	{
		cout << "Squirl::dtor()" << endl;
	}
	void Display()
	{
		cout << "Squirl::Display() ID:"<<GetID()<< endl;
	}
private:
};
/*
class LegendaryAnimal: public Animal
{
public:
  LegendaryAnimal() : m_a1(new Centipede()),
			m_a2(new Squirl())
  {
  }

  ~LegendaryAnimal() 
  { 
	delete m_a1; 
	delete m_a2;
  }

  void Display()
  {
	m_a1->Display();
	m_a2->Display();
	m_c.Display();
	m_sq.Display();
  }

private:
  Animal *m_a1;
  Animal *m_a2;
  Centipede m_c;
  Squirl m_sq;
};
*/
void Foo(Animal &a)
{
	a.Display();
}
void Foo()
{
	Animal::PrintCount();
}

Animal Foo(int i)
{
	Centipede ret;
	
	cout<<"Foo(int i)"<<endl;
	ret.Display();
	
	return ret;
}

void FiFi(Centipede c)
{
	c.Display();
}
//**************************************  MAIN  ***************************************
int main(int argc, char **argv, char **envp)
{
	Centipede c; 			// Ctor - init var
	Foo(c);					// Foo_ a pass by value, use CCtor
	Foo(3).Display();		// Foo_i over loading, Ctor ret, CCtor return by value

    FiFi(c);				// copy by value CCtor called from main

	Animal *array[] = 		// dynamic allocation in main,
	{
		new Centipede(),
		new Squirl(),
		new Centipede()
	};

	for(int i = 0; i < 3; ++i)
	{
		array[i]->Display();
	}
	for(int i = 0; i < 3; ++i)
	{
		delete array[i];
	}

	Animal arr2[] =				// Ctor for each item in the arr 
	{							// creating temps for centipede and squirl
		Centipede(),			// and then CCtor the temps to the actual array
		Squirl(),				// the temps must be Dtor
		Animal()				// animal is Ctor into the array, no temp no Dtor
	};

	for(int i = 0; i < 3; ++i) // call for func AnimalDisplay()
	{
		arr2[i].Display();
	}
	 
	Animal::PrintCount();		// call for AnimalPrintCount()
	Centipede c2;				// Ctor for Centipede
	c2.PrintCount();			// call for AnimalPrintCount
	
	Centipede arr3[4];				//  creates an array of 4 Centipedes, no Ctors
	Squirl *arr4 = new Squirl[4];	//
	delete [] arr4;					//
/*
	LegendaryAnimal *la1 = new LegendaryAnimal();
	LegendaryAnimal *la2 = new LegendaryAnimal(*la1);
	la1->Display();
	la2->Display();
	delete la1;
	la2->Display(); // this crashes. fix the bug!
	delete la2;
*/
	return 0;						// call for Dtor on c, array[], arr2[], c2, arr3[]
} 
