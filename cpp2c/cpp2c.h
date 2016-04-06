/****************************************************************************
	cpp2c
AUTHOR: omer ido                                                   
CREATE DATE: 05/04/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __CPP2C_H__
#define __CPP2C_H__

#include <iostream> 
	
#include <iostream>
using namespace std;

class Animal
{
public:
	Animal(): m_id(++s_count) // ctor
	{
		cout << "Animal::Ctor()"  << m_id << endl;
	}

	virtual ~Animal() // dtor
	{
		--s_count;
		cout << "Animal::Dtor()" << m_id  << endl;
	}

	Animal(const Animal &other): m_id(++s_count) // cctor
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
	int GetID() { return m_id; }

private:
	static int s_count;
	int m_id;
	Animal &operator=(const Animal &); // disabled
};

int Animal::s_count = 0;


class Centipede: public Animal
{
public:
	Centipede()
	: m_numLegs(46)
	{
		cout << "Centipede::Ctor()" << endl;
	}
	Centipede(const Centipede &other )
	: Animal(other),
	  m_numLegs(other.m_numLegs)
	{
		cout << "Centipede::CCtor()" << endl;
	}
	~Centipede() { cout << "Centipede::dtor()" << endl; }
	void Display() { cout << "Centipede::Display() ID:"<<GetID()<<"  num legs:" << m_numLegs << endl; }
	virtual void BuyShoes() { cout << "Centipede::BuyShues() ID:"<<GetID() << endl; }

private:
	int m_numLegs;
};

class Squirl: public Animal
{
public:
	Squirl() { cout << "Squirl::Ctor()" << endl; }
	Squirl(const Squirl &other ): Animal(other) { cout << "Squirl::CCtor()" << endl; }
	~Squirl() { cout << "Squirl::dtor()" << endl; }
	void Display() { cout << "Squirl::Display() ID:"<<GetID()<< endl; }

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
void Foo(Animal &a) { a.Display();}
void Foo(){ Animal::PrintCount(); }

Animal Foo(int i)
{
	Centipede ret;

	cout<<"Foo(int i)"<<endl;
	ret.Display();

	return ret;
}

void FiFi(Centipede c) { c.Display(); }

#endif /* ifndef __CPP2C_H__*/
