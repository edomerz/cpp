#include "serializer_ricki.h"

class Animal
{
	explicit Animal(size_t num_legs = 4, const std::string& str)

};

class Dog
{
	
};

Dog::string Dog::ToString() const
{

}

void Dog::FromString()

int main(int argc, char* argv[], char** envp)
{
	using namespace ilrd;
	using namespace std;

	// create serializer
	Serilaizer<Animal> s;

	// write


	// add members to factory map
	s.Add<Dog>();
	s.Add<Cat>();

	// read from file
	ifstream iFile;
	iFile.open(FILE_NAME);
	string input;
	while(boost::shared_ptr<Animal> obj = s.Create(iFile))
	
	
	return(0);
}
