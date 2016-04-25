/****************************************************************************
	tree
AUTHOR: omer ido                                                  
CREATE DATE: 24/04/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __TREE_H__
#define __TREE_H__

#define _BSD_SOURCE
#include <iostream> 
#include <vector>
#include <stdio.h>
#include <dirent.h>


namespace ilrd
{

/***************************************************************************/

class Component
{
public:
	Component(const std::string& name_);
	virtual ~Component();

	virtual void Display(int level = -1) const = 0;
	
	const std::string& GetName() const;
	virtual const Component* Find(const std::string& path_) const = 0;

private:
	std::string m_name;
};

/***************************************************************************/
class Directory: public Component
{
public:
	Directory(const std::string& name_);
	~Directory();

	void Display(int level = -1) const;
	void Add(Component* inst_);
	const Component* Find(const std::string& path_) const;

private:
	std::vector<Component*> v;
};


/***************************************************************************/
class File: public Component
{
public:
	File(const std::string& name_);
	~File();

	void Display(int level = 0) const;
	const Component* Find(const std::string& path_) const;

};

/***************************************************************************/

Component* CreateRepository(const std::string& path_);
const Component* FindPath(Component* repo_, const std::string& path_);

}

#endif /* ifndef __TREE_H__*/
