#include "tree.h"

namespace ilrd
{

Component::Component(const std::string& name_): m_name(name_)
{}

Dirctory::Dirctory(const std::string& name_): Componenet(name_), v(0), level(0)
{}

Dirctory::~Dirctory()
{
	for(int i = 0, int size = v.size(); i < size; ++i)
	{
		delete v[i];
	} 
}



File::File(const std::string& name_): Component(name_)
{}






}

