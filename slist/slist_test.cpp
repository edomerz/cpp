#include "slist.h"
#include <string>
using namespace ilrd;

#define L 2

class Person
{
	std::string name;
	int iq;

public:
	explicit Person(): name(""), iq(0)
	{}
	explicit Person(std::string name_, int iq_): name(name_), iq(iq_)
	{}

	Person(const Person& other_): name(other_.name), iq(other_.iq)
	{}

	Person& operator=

};

int main(void)
{
	std::cout<<"hello\n";

	Person p_list[L];
	p_list[0].iq = 1;
	p_list[0].name = "ran";
	p_list[1]("ricki", 2);

	Slist<Person> list;

	std::cout<<list.IsEmpty()<<std::endl;

	std::cout<<list.Count()<<std::endl;

//	list.Pop();
//
//	for(int i = 2; L > 0; --i)
//	{
//		list.Push(p_list[i]);
//
//	}
//
////	list.Push(10);
//	list.PrintList();
//	std::cout<<list.IsEmpty()<<std::endl;
//	std::cout<<list.Count()<<std::endl;
//
//
//	for(int i = 0; i < 20; ++i)
//	{
//		std::cout<<list.Pop()<<'\n';
//	}
//
//


	return(0);
}
