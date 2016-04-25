#include "tree.h"
#include <string.h>

namespace ilrd
{
/********************************** Component *********************************/

Component::Component(const std::string& name_): m_name(name_)
{}

Component::~Component()
{}

const std::string& Component::GetName() const
{
	return(m_name);
}






/********************************** Dirctory ********************************/

Directory::Directory(const std::string& name_): Component(name_), v(0ul, 0)
{}

Directory::~Directory()
{
	for(int i = 0, size = v.size(); i < size; ++i)
	{
		delete v[i];
	} 
}

void Directory::Display(int level) const
{
	++level;
	std::cout << std::string(level, '-') << GetName() << std::endl;

	for(int i = 0, v_size = v.size(); i < v_size; ++i)
	{
		v[i]->Display(level);
	}
}

void Directory::Add(Component* inst_)
{
	v.push_back(inst_);
}


/************************************ File **********************************/

File::File(const std::string& name_): Component(name_)
{}

File::~File()
{}

void File::Display(int level) const
{
	std::cout << std::string(level, '-') << GetName() << std::endl;
}

void File::Find(std::string& path_) const
{

}



/****************************** GLOBAL FUNCTIONS *****************************/

Component* CreateRepository(const std::string& path_)
{
	struct dirent *pDirnet = 0;
	DIR *pDir = 0;
	Directory *dir = new Directory(path_.c_str());
	
	pDir = opendir(path_.c_str());
	if(!pDir)
	{
		std::cout << "Cannot open the dir " << path_ << std::endl;
		return(NULL);
	}
	
	while ((pDirnet = readdir(pDir))) 
	{
		if(pDirnet->d_type == DT_REG)
		{
			Component* tmp = new File(pDirnet->d_name);
			dir->Add(tmp);
			
		}
		else if(pDirnet->d_type == DT_DIR)
		{
			if(strncmp(pDirnet->d_name, ".", 1) && strncmp(pDirnet->d_name, "..", 2))
			{
				std::string new_path = path_  + '/'+ pDirnet->d_name;
				std::cout << "\t\t\tnew path" << new_path << std::endl;
				dir->Add(CreateRepository(new_path));
			}
//			Component* tmp = new Directory(pDirnet->d_name);
//			dir->Add(tmp);
			

		}
        std::cout << pDirnet->d_name << std::endl;
    }
    
    closedir (pDir);
    
    return(dir);
}

Component* FindPath(Component* repo_, const std::string& path_)
{

	Component* tmp = repo_;
	tmp->Display();

	return(tmp);
}


}

