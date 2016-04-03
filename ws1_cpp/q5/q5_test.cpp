#include "q5.h"

struct Person_t
{
	int age;
	int key;
}Person_t;
typedef struct Person_t Person;


struct List_t
{
	void *Person;
}List_t;
typedef struct List_t List;

void  *ll_find(List *ll, int key)
{
	return ll;
}

void foo(List *ll, int key, int age)
{
	void *vv = ll_find(ll, key);
	
	// list contains Person data, so we want to
	// convert the void* to Person to access it
	//Person *p = (Person*)ll; // ll is wrong here, vv is the correct
	Person *p = static_cast<Person*>(vv);
	p->age = age;
}

int main(void)
{
	Person p;
	List l;

	p.age = 50;
	p.key = 3;
	l.Person = &p;

	foo(&l, 4, 10);
	
	return(0);
}
