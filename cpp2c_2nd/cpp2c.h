
#include <stdio.h>

int s_count;

typedef struct animal_vtbl animal_vtbl;
typedef struct cen_vtbl cen_vtbl;
typedef struct sq_vtbl sq_vtbl;
typedef struct leg_vtbl leg_vtbl;

void PrintCount(Animal* this);

void Foo_ref(Animal* a);
void Foo(void);
void Foo_int(int i);
void FiFi(Centipede c);

typedef struct Animal
{
	animal_vtbl* vptr;
	int animal_id;
}Animal;

typedef struct Centipede
{
	cen_vtbl* vptr;
	int cen_numLegs
}Centipede;

typedef struct Squirl
{
	Squirl* vptr;
}Squirl;

typedef struct LegendaryAnimal
{
	leg_vtbl* vptr;
	Animal* leg_a1;
	Animal* leg_a2;
	Centipede leg_c;
	Squirl leg_sq;
}LegendaryAnimal;

typedef strcut animal_vtbl
{
	void (*animalDtor)(Animal* this);
	void (*animalDisplay)(Animal* this);
}animal_vtbl;
