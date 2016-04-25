#include "sharedptr.h"

using namespace std;
using namespace ilrd;

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

int main(int argc, char* argv[], char** envp)
{
	Animal a1;
	Centipede c1;

	SharedPtr<Animal> pa(&a1);
	SharedPtr<Centipede> pc(&c1);

	pa = pc;

	return(0);
}
