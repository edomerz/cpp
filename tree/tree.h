/****************************************************************************
	tree
AUTHOR: omer ido                                                  
CREATE DATE: 24/04/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __TREE_H__
#define __TREE_H__

#include <iostream> 
#include <vector>

namespace ilrd
{

class Component
{
public:
	Component(const std::string& name_);
	virtual ~Component();

	virtual void Display(int level) const = 0;
	
private:
	std::string m_name;
};

class Directory: public Component
{
public:
	Directory(const std::string& name_);
	~Directory();

	void Dispaly() const;
	void Add(Component* inst_);

private:
	std::vector<Component*> v;
	size_t level;
};

class File: public Component
{
	File(const std::string& name_);
	~File();

	void Display(int level) const;

};



void CreateRepository(const std::string& path_);
Component* FindPath(Component* repo_, const std::string& path_);

}

#endif /* ifndef __TREE_H__*/
