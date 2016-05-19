#include <stdio.h>
#include <stdlib.h>

/* VIRTUAL TABLES TYPEDEFS */
typedef struct animal_virtual_table animal_vtable_t;
typedef struct centipede_virtual_table centipede_vtable_t;
typedef struct squirrel_virtual_table squirrel_vtable_t;
typedef struct legendary_animal_virtual_table legendary_animal_vtable_t;

/* STRUCTS DECLARATIONS & TYPEDEFS */
typedef struct Animal
{
	animal_vtable_t *vtable_ptr;
	int m_id;
} Animal;

typedef struct Centipede
{
	Animal animal;
	int m_numLegs;
} Centipede;

typedef struct Squirrel
{
	Animal animal;
} Squirrel;

typedef struct LegendaryAnimal
{
	Animal animal;
	Animal *m_a1;
	Animal *m_a2;
	Centipede m_c;
	Squirrel m_sq;
} LegendaryAnimal;

/* FUNCTIONS DECLARATIONS */
void AnimalCtor(Animal *this);
void AnimalDtor(Animal *this); /* virtual function */
void AnimalCopyCtor(Animal *this, const Animal *other);
/* Disabled: Animal *AnimalAssignmentOperator(Animal *this, const Animal *other) */
void AnimalDisplay(Animal *this); /* virtual function */
void AnimalPrintCount(void);
static int AnimalGetID(Animal *this);

void CentipedeCtor(Centipede *this);
void CentipedeCopyCtor(Centipede *this, const Centipede *other);
void CentipedeDtor(Centipede *this); /* virtual function */
void CentipedeDisplay(Centipede *this); /* virtual function */
void CentipedeBuyShoes(Centipede *this); /* virtual function */

void SquirrelCtor(Squirrel *this);
void SquirrelCopyCtor(Squirrel *this, const Squirrel *other);
void SquirrelDtor(Squirrel *this); /* virtual function */
void SquirrelDisplay(Squirrel *this); /* virtual function */

void LegendaryAnimalCtor(LegendaryAnimal *this);
void LegendaryAnimalCopyCtor(LegendaryAnimal *this, const LegendaryAnimal *other);
void LegendaryAnimalDtor(LegendaryAnimal *this); /* virtual function */
void LegendaryAnimalDisplay(LegendaryAnimal *this); /* virtual function */

/* VIRTUAL TABLES DECLARATIONS */
struct animal_virtual_table
{
	void(*Dtor)(Animal *this);
	void(*Display)(Animal *this);
};
animal_vtable_t animal_vtable = { AnimalDtor, AnimalDisplay };

struct centipede_virtual_table
{
	void(*Dtor)(Centipede *this);
	void(*Display)(Centipede *this);
	void(*CentipedeBuyShoes)(Centipede *this);
};
centipede_vtable_t centipede_vtable = { CentipedeDtor, CentipedeDisplay, CentipedeBuyShoes };

struct squirrel_virtual_table
{
	void(*Dtor)(Squirrel *this);
	void(*Display)(Squirrel *this);
};
squirrel_vtable_t squirrel_vtable = { SquirrelDtor, SquirrelDisplay };

struct legendary_animal_virtual_table
{
	void(*Dtor)(LegendaryAnimal *this);
	void(*Display)(LegendaryAnimal *this);
};
legendary_animal_vtable_t legendary_vtable = { LegendaryAnimalDtor, LegendaryAnimalDisplay };

/* STATIC MEMBERS DEFINITIONS */

/* int Animal::s_count = 0; */
/* we cant put it as a member of the animal struct, since the C compiler
* does not allow static member inside a struct */
static int s_count = 0;

static void AnimalPrintCount()
{
	printf("s_count: %d\n", s_count);
}

/* PROTECTED MEMBER FUNCTION DECLARATION */
/* decalraing it static to make it an internal linkage */
static int AnimalGetID(Animal *this)
{
	return this->m_id;
}

/* ANIMAL'S MEMBER FUNCTIONS DEFINITIONS */

void AnimalCtor(Animal *this)
{
	this->vtable_ptr = &animal_vtable;
	this->m_id = ++s_count;

	printf("AnimalCtor() ID: %d\n", this->m_id);
}

/* this Copy Ctor is kind of stupid, in the sense that it is stupid
* to copy the ID (that should be unique, if you think about it).
* To solve this stupidity, we/they should have made Animal an
* abstract class. */
void AnimalCopyCtor(Animal *this, const Animal *other)
{
	/* At first, I was wrong and wrote:
	this->vtable_ptr = other->vtable_ptr;
	this is wrong, since it allows *this to be constructed from a derived class,
	and this may cause bugs.
	for example, say the user wants to do this: Animal a1(c1), and intends
	to construct an animal from the 'animal portion' of the c1 centipede.
	then, it may try to call a virtual function of ANIMAL (since this is what he
	has in hand - an Animal), but alas! this will actually call a CENTIPEDE's
	virtual table function - that may use a Centipede's unique data members -
	and then it would crash! */ 
	this->vtable_ptr = &animal_vtable;
	
	this->m_id = other->m_id; /* this is useless, but I do a full copying */
	this->m_id = ++s_count;

	printf("AnimalCopyCtor() ID: %d\n", this->m_id);
}

void AnimalDtor(Animal *this)
{
	--s_count;
	printf("AnimalDtor() ID: %d\n", this->m_id);
}

void AnimalDisplay(Animal *this)
{
	printf("AnimalDisplay() ID: %d\n", this->m_id);
}

/* CENTIPEDE'S MEMBER FUNCTIONS DEFINITIONS */

void CentipedeCtor(Centipede *this)
{
	AnimalCtor(&(this->animal));
	this->animal.vtable_ptr = (animal_vtable_t *)&centipede_vtable;

	this->m_numLegs = 46;
	printf("CentipedeCtor() ID: %d\n", this->animal.m_id);
}

/* Centipede Copy Ctor need not to instantiate Centipede(+Animal),
* since this, for example: Centipede c2(c1) is first instantiating
* Animal+Centipede for c2, i.e., it ONLY ALLOCATES AN ADDRESS OF
* ANIMAL+CENTIPEDE, BUT NOT YET INITIALIZING IT. THE INITIALIZING
* OPERATION IS THE JOB OF THE COPY CTOR. */
void CentipedeCopyCtor(Centipede *this, const Centipede *other)
{
	AnimalCopyCtor(&this->animal, &other->animal);
	this->animal.vtable_ptr = (animal_vtable_t *)&centipede_vtable;

	this->m_numLegs = 46;

	printf("CentipedeCopyCtor() ID: %d\n", AnimalGetID((Animal *)this));
}

void CentipedeDtor(Centipede *this)
{
	printf("CentipedeDtor() ID:, %d\n", AnimalGetID((Animal *)this));
	AnimalDtor(&this->animal);
}

void CentipedeDisplay(Centipede *this)
{
	printf("CentipedeDisplay() ID: %d, num legs: %d\n",
		AnimalGetID((Animal *)this), this->m_numLegs);
}

void CentipedeBuyShoes(Centipede *this)
{
	printf("CentipedeBuyShoes() ID: %d\n", AnimalGetID((Animal *)this));
}

/* SQUIRREL'S MEMBER FUNCTIONS DEFINITIONS */

void SquirrelCtor(Squirrel *this)
{
	AnimalCtor(&(this->animal));
	this->animal.vtable_ptr = (animal_vtable_t *)&squirrel_vtable;

	printf("SquirrelCtor() ID: %d\n", this->animal.m_id);
}

/* Squirrel CopyCtor need not to instantiate Centipede(+Animal),
* since this - see Centipede Copy Ctor's comment. */
void SquirrelCopyCtor(Squirrel *this, const Squirrel *other)
{
	AnimalCopyCtor(&this->animal, &other->animal);
	this->animal.vtable_ptr = (animal_vtable_t *)&squirrel_vtable;

	printf("SquirrelCopyCtor() ID: %d\n", AnimalGetID((Animal *)this));
}

void SquirrelDtor(Squirrel *this)
{
	printf("SquirrelDtor() ID:, %d\n", AnimalGetID((Animal *)this));
	AnimalDtor(&this->animal);
}

void SquirrelDisplay(Squirrel *this)
{
	printf("SquirrelDisplay() ID: %d\n", AnimalGetID((Animal *)this));
}

void LegendaryAnimalCtor(LegendaryAnimal *this)
{
	AnimalCtor(&(this->animal));
	this->animal.vtable_ptr = (animal_vtable_t *)&legendary_vtable;

	this->m_a1 = malloc(sizeof(Centipede));
	CentipedeCtor((Centipede *)this->m_a1);

	this->m_a2 = malloc(sizeof(Squirrel));
	SquirrelCtor((Squirrel *)this->m_a2);

	CentipedeCtor(&this->m_c);
	SquirrelCtor(&this->m_sq);

	printf("LegendaryCtor() ID: %d\n", this->animal.m_id);
}

void LegendaryAnimalCopyCtor(LegendaryAnimal *this, const LegendaryAnimal *other)
{
	AnimalCtor(&(this->animal));
	this->animal.vtable_ptr = (animal_vtable_t *)&legendary_vtable;

	this->m_a1 = malloc(sizeof(Centipede));
	CentipedeCopyCtor((Centipede *)this->m_a1, (Centipede *)other->m_a1);

	this->m_a2 = malloc(sizeof(Squirrel));
	SquirrelCopyCtor((Squirrel *)this->m_a2, (Squirrel *)other->m_a2);

	CentipedeCopyCtor(&this->m_c, &other->m_c);
	SquirrelCopyCtor(&this->m_sq, &other->m_sq);

	printf("LegendaryCopyCtor() ID: %d\n", this->animal.m_id);
}

void LegendaryAnimalDtor(LegendaryAnimal *this)
{
	/* i dont know why it destroys the m_a1 & m_a2 pointers
	in the order they were created, but m_c & m_sq at the
	opposite order. */

	this->m_a1->vtable_ptr->Dtor(this->m_a1);
	free(this->m_a1);
	this->m_a2->vtable_ptr->Dtor(this->m_a2);
	free(this->m_a2);

	printf(" LegendaryAnimalDtor() ID:, %d\n", AnimalGetID((Animal *)this));

	SquirrelDtor(&this->m_sq);
	CentipedeDtor(&this->m_c);

	AnimalDtor(&this->animal);
}

void LegendaryAnimalDisplay(LegendaryAnimal *this)
{
	printf("LegendaryAnimalDisplay() ID: %d\n", AnimalGetID((Animal *)this));
	this->m_a1->vtable_ptr->Display(this->m_a1);
	this->m_a2->vtable_ptr->Display(this->m_a2);
	CentipedeDisplay(&this->m_c);
	SquirrelDisplay(&this->m_sq);
}

/* FooAnimal is a C implementation of this C++ function:
* void Foo(Animal &a) { a.Display(); }
* Note 2 changes:
* 1. the function's name (to resemeble the name mangling)
* 2. the function's parameter: the C++'s reference& is implemented using a pointer
* Also note that this function utilizes the polymorphism priniciple:
* we can pass a pointer to derived class (e.g., Centipede *), and the compiler
* understands that since Animal is (1) a base class that (2) has a virtual function,
* then a POINTER to this base class may actually point EITHER to a base class OR
* to a derived class. To 'determine' what this pointer is actually pointing at, it simply
* goes to the virtual table pointer, located inside Animal (which is in itself a data member
* in every derived class), and simply calls the correct function. */
void FooAnimal(Animal *a)
{
	a->vtable_ptr->Display(a);
}

/* AnimalFooVoid is a C implementation of this C++ function:
* void Foo(){ Animal::PrintCount(); }
* This function is never called anyways. */
void AnimalFooVoid(void)
{
	AnimalPrintCount();
}

/* FooInt is a C implementation of this C++ function:
* Animal Foo(int i)(){ Centipede ret; ret.Display(); return ret;}
* Note 2 changes:
* 1. the function's name (to resemeble the name mangling)
* 2. the function's prototype: insted of returning Animal it returns
* nothing (void), and thus - in order to 'mimic' the returned Animal, it
* gets an Animal *; will soon see what do we do with it, but first let's
* exmine the following question: why can't we simply stick to the original
* prototype, and simply return an Animal by value? isn't C's return-by-value
* copy the returned struct bitwise?
* the answer is simple: C do indeed return the struct bitwise, but this lacks
* the operation of C++ of CALLING A COPY CTOR WHEN RETURNING BY VALUE.
* Let's make things more detailed:
* when a call is made to the C++'s Animal Foo(int i), here's what happens:
* 1. the compiler instantiates a temporary object at the place (on which the pc register
* points to) the returned value will be passed once Foo returns.
* Note: this is only an INSTANCIATION, and not yet an initialization, a constructing.
* 2. we can now enter the function's block, and we first constructing a Centepede
* (meaning a call to Ctor Animal, and then executing the rest of the Centepede Ctor)
* 3. Calling Display, pretty simple.
* 4. at this point, the C++ implementation has a 'return' expression. this expression
* is what finally initialize the passed Animal * - and it does so using a Copy Ctor
* of Animal - which takes as a second argument the 'animal portion' of the Centepede.
* after the copy has completed, it means "we returned Animal by value" the C++ way.
* 5. at the end, at the closing }, the Dtor of the Centipede is called.
* 6. at the ';' symbol of the 'Foo(3).Display();', the compiler finally destroys the temp
* Animal he instantiated, so the AnimalDtor is called. */
void FooInt(Animal *temp_animal, int i)
{
	Centipede returned;

	printf("inside FooInt\n");

	CentipedeCtor(&returned);

	printf("FooInt\n");
	CentipedeDisplay(&returned);

	AnimalCopyCtor(temp_animal, &(returned.animal));

	CentipedeDtor(&returned);

	printf("out of FooInt\n");
}

/* FiFi is a C implementation of this C++ function:
* void FiFi(Centipede c){ c.Display(); }
* Note 2 things: we create a temporary inside FiFi, that gets
* the Centipede passed bitwise into FiFi (I don't know what it means.
* please refer to the comment before the call to FiFi inside main),
* and we operate with it inside Centipede. */
void FiFi(Centipede c)
{
	CentipedeDisplay(&c);
}

int main()
{
	int i = 0;

	printf("*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"\t    void FooAnimal(Animal *a) \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* Centipede c; */
	Centipede centipede1;
	CentipedeCtor(&centipede1);
	
	/* Foo(c); */
	FooAnimal((Animal *)&centipede1);

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"\tvoid FooInt(Animal *temp_animal, int i) \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* please refer to the comment of FooInt to understand:
	* 1. why we create a temp Animal
	* 2. why we create it here (and not in FooInt itself) */
	
	/* Foo(3).Display(); */
	Animal temp_animal;
	FooInt(&temp_animal, 3);
	AnimalDisplay(&temp_animal);
	AnimalDtor(&temp_animal);

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"\t      FiFi(Centipede c) \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* NOTE: when disassembling the C++ main function, the call to FiFi(c) is
	* disassembled into the following lines snippet:
	* FiFi(c);
	* 0000000000400fcf:   lea     -0x58(%rbp),%rdi
	* 0000000000400fd3:   lea     -0x28(%rbp),%rsi
	* 0000000000400fd7:   callq   0x4025e0 <Centipede::Centipede(Centipede const&)>
	* 0000000000400fdc:   jmpq    0x400fe1 <main(int, char**, char**)+417>
	* 0000000000400fe1:   lea     -0x58(%rbp),%rdi
	* 0000000000400fe5:   callq   0x400dd0 <FiFi(Centipede)>
	* 0000000000400fea:   jmpq    0x400fef <main(int, char**, char**)+431>
	* 0000000000400fef:   lea     -0x58(%rbp),%rdi
	* 0000000000400ff3:   callq   0x402420 <Centipede::~Centipede()>
	* so you can see that call to the Centipede's Copy Ctor is done
	* BEFORE WE ENTER TO FiFi! In addition, the call to Centipede's Dtor
	* is done also OUT OF FiFi! */
	
	/* FiFi(c); */
	Centipede temp;
	CentipedeCopyCtor(&temp, &centipede1);
	FiFi(centipede1);
	CentipedeDtor(&temp);

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"\t       Animal *array[] \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* C implementation of the following C++ expression:
	* Animal *array[] = { new Centipede(), new Squirrel(), new Centipede() };
	* the above function dynamically instanitate & initialize a Centipede,
	* Squirrel and an Animal. However, since the array is an Animal * array,
	* each pointer in it can actually be only a pointer to Animal *.*/	
	
	/* Animal *array[] =
	   { new Centipede(), new Squirrel(), new Centipede() }; */	
	Animal *animal_ptr_array[3];

	animal_ptr_array[0] = malloc(sizeof(Centipede));
	CentipedeCtor((Centipede *)animal_ptr_array[0]);

	animal_ptr_array[1] = malloc(sizeof(Squirrel));
	SquirrelCtor((Squirrel *)animal_ptr_array[1]);

	animal_ptr_array[2] = malloc(sizeof(Centipede));
	CentipedeCtor((Centipede *)animal_ptr_array[2]);

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"  for (int i = 0; i < 3; ++i) array[i]->Display(); \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* we have to go to Display through the vtable, because the animal *
	* sometimes points to the base class (Animal) but sometimes to the
	* derived class (Centipede or Squirrel). */
	
	/* for(int i = 0; i < 3; ++i) array[i]->Display(); */
	for (i = 0; i < 3; ++i)
	{
		animal_ptr_array[i]->vtable_ptr->Display(animal_ptr_array[i]);
	}

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"    for (int i = 0; i < 3; ++i) delete array[i] \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* we have to go to Dtor through the vtable, for the same reason we did
	* that at the latter for loop. */

	/* for(int i = 0; i < 3; ++i) delete array[i]; */
	for (i = 0; i < 3; ++i)
	{
		animal_ptr_array[i]->vtable_ptr->Dtor(animal_ptr_array[i]);
		free(animal_ptr_array[i]);
	}

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		" Animal arr2[] = {Centipede(), Squirrel(), Animal()} \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* C implementation of the following C++ expression:
	* Animal arr2[] = { Centipede(), Squirrel(), Animal() };
	* Note that since arr2 is an Animal array, it cannot hold Neither
	* Centipede nor Squirrel objects. Therefore, both of them are constructed
	* as temp objects, and then an Animal copy constructor is called
	* and copies their 'animal portion', and then the temp objects are
	* being destructed. */
	
	/* Animal arr2[] =
	   { Centipede(), Squirrel(), Animal() }; */
	
	Animal arr2[3];

	/* This is an Animal-type array, so we take the 'slice' the
	   animal portion of each temporary */
	Centipede temp_centipede;
	CentipedeCtor(&temp_centipede);
	AnimalCopyCtor(&arr2[0], &(temp_centipede.animal));
	CentipedeDtor(&temp_centipede);

	Squirrel temp_squirrel;
	SquirrelCtor(&temp_squirrel);
	AnimalCopyCtor(&arr2[1], &(temp_squirrel.animal));
	SquirrelDtor(&temp_squirrel);

	AnimalCtor(&arr2[2]);

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		" for (int i = 0; i < 3; ++i) array2[i].Display(); \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* for (int i = 0; i < 3; ++i) array2[i].Display(); */
	for (int i = 0; i < 3; ++i)
	{
		/* NOTE: this: arr2[i].vtable_ptr->Display(&arr2[i]);
		* is wrong. The reason is that arr2 is not an Animal * array,
		* but simply an Animal array. therefore, since the compiler has
		* no doubt that arr2[i] will always be a Base class (and not a
		* Derived class), it doesn't need to go to Display through the vtable,
		* but can go directly to AnimalDisplay. */
		AnimalDisplay(&arr2[i]);
	}

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"\t\t  AnimalPrintCount \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
	/* Note that PtrintCount is a C++ static member function, meaning
	   there is no need for an instance of Animal when calling it */
	
	/* Animal::PrintCount(); */
	AnimalPrintCount();

	/* Centipede c2;
	   c2.PrintCount(); */
	Centipede centipede2;
	CentipedeCtor(&centipede2);
	AnimalPrintCount();

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"\t     Centipede arr3[4]; \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
	
	/* Centipede arr3[4]; */
	Centipede arr3[4];
	for (i = 0; i < 4; ++i)
	{
		CentipedeCtor(&arr3[i]);
	}

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"      Squirrel *arr4 = new Squirrel[4]; \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* Squirrel *arr4 = new Squirrel[4]; */
	Squirrel *arr4 = malloc(sizeof(Squirrel[4]));
	for (i = 0; i < 4; ++i)
	{
		SquirrelCtor(&arr4[i]);
	}

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"\t\t  delete[] arr4; \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* delete [] arr4; */
	for (i = 3; i >= 0; --i)
	{
		SquirrelDtor(&arr4[i]);
	}
	free(arr4);

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"  LegendaryAnimal *la1 = new LegendaryAnimal(); \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* LegendaryAnimal *la1 = new LegendaryAnimal(); */
	LegendaryAnimal *la1 = malloc(sizeof(LegendaryAnimal));
	LegendaryAnimalCtor(la1);

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		" LegendaryAnimal *la2 = new LegendaryAnimal(*la1); \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* LegendaryAnimal *la2 = new LegendaryAnimal(*la1); */
	LegendaryAnimal *la2 = malloc(sizeof(LegendaryAnimal));
	LegendaryAnimalCopyCtor(la2, la1);

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"\t    la1->Display(); \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* la1->Display(); */
	LegendaryAnimalDisplay(la1);

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"\t    la2->Display(); \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* la2->Display(); */
	LegendaryAnimalDisplay(la2);

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"\t      delete la1; \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* delete la1; */;
	LegendaryAnimalDtor(la1);
	free(la1);

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"\t   la2->Display(); \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* la2->Display(); */
	LegendaryAnimalDisplay(la2);

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"\t      delete la1; \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");

	/* delete la2; */;
	LegendaryAnimalDtor(la2);
	free(la2);

	printf("\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n"
		"\t  Destructing leftovers \n"
		"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
	/* } */
	for (i = 3; i >= 0; --i)
	{
		CentipedeDtor(&arr3[i]);
	}

	CentipedeDtor(&centipede2);

	for (i = 2; i >= 0; --i)
	{
		AnimalDtor(&arr2[i]);
	}

	CentipedeDtor(&centipede1);

	return (0);
}

