#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/* int animal::s_count = 0 */
int animal_s_count = 0;


typedef struct Animal Animal;
typedef struct Centipede Centipede;
typedef struct Squirl Squirl;
typedef struct LegendaryAnimal LegendaryAnimal;


void AnimalDisplay(Animal* this);
void CentipedeDisplay(Animal* this);
void SquirlDisplay(Animal* this);
void

void CentipedeBuyShoes(Animal* this);


void AnimalDtor(Animal* this);
void CentipedeDtor(Centipede* this);
void SquirlDtor(Squirl* this);


typedef struct animal_vtbl
{
	void (*Display)(Animal* this);
	void (*Dtor)(Animal* this);
}animal_vtbl;
animal_vtbl the_animal_vtbl = {AnimalDisplay, AnimalDtor};

typedef struct centipede_vtbl
{
	void(*Dislplay)(Animal* this);
	void (*Dtor)(Centipede* this);
	void(*BuyShoes)(Animal* this);
}centipede_vtbl;
centipede_vtbl the_centipede_vtbl = { CentipedeDisplay, CentipedeDtor, CentipedeBuyShoes};

typedef struct squirl_vtbl
{
	void(*Dislplay)(Animal* this);
	void (*Dtor)(Squirl* this);
}squirl_vtbl;
squirl_vtbl the_squirl_vtbl = {SquirlDisplay, SquirlDtor};

struct Animal
{
	animal_vtbl* vptr;
	int m_id;
};

struct Centipede
{
	Animal a;
	int m_numLegs;
};

struct Squirl
{
	Animal a;
};

void AnimalCtor(Animal* this)
{
	++animal_s_count;
	assert(this);
	this->vptr = &the_animal_vtbl;

	this->m_id = animal_s_count;
	printf("AnimalCtor(): %d\n", this->m_id);
}

void AnimalCctor(Animal* this, Animal* other)
{
	assert(this); assert(other);
//	++animal_s_count;
	this->m_id = ++animal_s_count;

	//this->vptr = other->vptr; // this is a bug we need to prevent slicing
	this->vptr = &the_animal_vtbl;
	printf("AnimalCctor(): %d\n", this->m_id);
}

void AnimalDtor(Animal* this)
{
	assert(this);
//	this->vptr = &the_animal_vtbl; // make sure that vtbl is correct
	--animal_s_count;
	printf("AnimalDtor() %d\n", this->m_id);
//	free(this);
}

void AnimalDisplay(Animal* this)
{
	printf("Animal::Display() : %d\n", this->m_id);
}

void AnimalPrintCount()
{
	printf("animal_s_count: %d\n", animal_s_count);
}

int AnimalGetID(Animal* this)
{
	return(this->m_id);
}

void CentipedeCtor(Centipede* this)
{
	AnimalCtor(&this->a);
	this->a.vptr = (animal_vtbl*)&the_centipede_vtbl;
	this->m_numLegs = 46;
	printf("CentipedeCtor()\n");
}

void CentipedeCctor(Centipede* this,  Centipede* other)
{
	assert(this); assert(other);
//	this->a = other->a;
	AnimalCctor(&(this->a), &(other->a));
	this->a.vptr = &the_centipede_vtbl; // centipede can be a base class to other class
	this->m_numLegs = other->m_numLegs;
	printf("CentipedeCctor()\n");
}
void CentipedeDisplay(Animal* this)
{
	printf("Centipede::Display() ID: %d  num legs: %d\n",
								AnimalGetID(this), ((Centipede*)this)->m_numLegs);
}

void CentipedeBuyShoes(Animal* this)
{
	printf("Centipede::BuyShues() ID:%d\n", AnimalGetID(this));
	return;
}

void CentipedeDtor(Centipede* this)
{
	this->a.vptr = &the_animal_vtbl; // return the correct table
	printf("CentipedeDtor\n");
	AnimalDtor(&(this->a));
}

void SquirlCtor(Squirl* this)
{
	assert(this);
	AnimalCtor(&this->a);
	this->a.vptr = (animal_vtbl*)&the_squirl_vtbl;
	printf("SquirlCtor\n");
}

void SquirlCctor(Squirl* this, Squirl* other)
{
	assert(this); assert(other);
	AnimalCctor(&(this->a), &(other->a));
	printf("SquirlCctor\n");
}

void SquirlDtor(Squirl* this)
{
	printf("SquirlDtor\n");
	AnimalDtor(&this->a);
}

void SquirlDisplay(Animal* this)
{
	printf("Squirl::Display() ID:%d\n", AnimalGetID(this));
}

void Foo_ref(Animal* a)
{
	a->vptr->Display(a);
}

void Foo_v(void)
{
	AnimalPrintCount();
}

void Foo_i(int i, Animal* ret_a)
{
	Centipede ret;
	CentipedeCtor(&ret);

	printf("Foo(int i)\n");

//	ret.a.vptr->Display((Animal*)&ret);// no need for vtbl explicit call to cen display
	CentipedeDisplay(&ret);

	AnimalCctor(ret_a, (Animal*)&ret);

	CentipedeDtor(&ret);
}


void FiFi(Centipede c)
{
	Centipede tmp;
	CentipedeCctor(&tmp, &c);
	CentipedeDisplay((Animal*)&tmp);
	CentipedeDtor(&tmp);
}

int main()
{
	// Centipede c;
	Centipede c;
	CentipedeCtor(&c);

	//Foo(c);
	Foo_ref((Animal*)&c);

	// Foo(3).Display();
	Animal tmp1;
	Foo_i(3, &tmp1);
	AnimalDisplay((&tmp1);
	AnimalDtor((&tmp1);

	//FiFi(c);
	printf("*************FiFi*************\n");
	FiFi(c);

	//Animal *array[] =
	printf("**************Animal *array************\n");
	Animal *array[3];
	array[0] =(Animal*)malloc(sizeof(Centipede));
	array[1] = (Animal*)malloc(sizeof(Squirl));
	array[2] = (Animal*)malloc(sizeof(Centipede));
	CentipedeCtor((Centipede*)array[0]);
	SquirlCtor((Squirl*)array[1]);
	CentipedeCtor((Centipede*)array[2]);

	// for(int i = 0; i < 3; ++i) array[i]->Display();
	for(int i = 0; i < 3; ++i)
	{
		array[i]->vptr->Display(array[i]);
	}

	// for(int i = 0; i < 3; ++i)  delete array[i];
	for(int i = 0; i < 3; ++i)
	{
		array[i]->vptr->Dtor(array[i]);
		free(array[i]);
	}

	// Animal arr2[] =
	printf("**************Animal arr2************\n");
	Animal arr2[3];

	Centipede ct1;
	CentipedeCtor(&ct1);
	AnimalCctor(&arr2[0], (Animal*)&ct1);

	Squirl st1;
	SquirlCtor(&st1);
	AnimalCctor(&arr2[1], (Animal*)&st1);

	AnimalCtor(&arr2[2]);

//	arr2[1].vptr->Dtor(&arr2[1]);
	SquirlDtor((Squirl*)&st1);

//	arr2[0].vptr->Dtor(&arr2[0]);
	CentipedeDtor((Centipede*)&ct1);


// for(int i = 0; i < 3; ++i)
	printf("************* line 182 for************\n");
	for(int i = 0; i < 3; ++i)
	{
		AnimalDisplay(&arr2[i]);
	}

	// Animal::PrintCount();
	printf("************* Animal::PrintCount();************\n");
	AnimalPrintCount();

	//Centipede c2;
	printf("************* Centipede c2;************\n");
	Centipede c2;
	CentipedeCtor(&c2);

	// c2.PrintCount();
	printf("************* c2.PrintCount();************\n");
	AnimalPrintCount();


	// Centipede arr3[4];
	printf("************* Centipede arr3[4];************\n");
	Centipede arr3[4];

	//Squirl *arr4 = new Squirl[4];
	printf("************* Squirl *arr4 = new Squirl[4];************\n");
	Squirl *arr4 = malloc(sizeof(Squirl) * 4);
	for(int i = 0; i < 4; ++i)
	{
		SquirlCtor(&arr4[i]);
	}

	//delete [] arr4;
	printf("************* delete [] arr4;************\n");
	for(int i = 3; i >= 0; --i)
	{
		SquirlDtor(&arr4[i]);
	}

	//return 0;
	printf("************* return 0;************\n");
	CentipedeDtor(&c2);
	printf("\n");

	for(int i = 2; i >= 0; --i)
	{
		AnimalDtor(&arr2[i]);
	}

	printf("\n");
	CentipedeDtor(&c);
}
