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

/********************************** Directory ********************************/

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
	std::cout << std::string(level, '-') << "[Dir]" << GetName() << std::endl;

	for(int i = 0, v_size = v.size(); i < v_size; ++i)
	{
		v[i]->Display(level);
	}
}

void Directory::Add(Component* inst_)
{
	v.push_back(inst_);
}

const Component* Directory::Find(const std::string& path_) const
{
	const Component* ret = NULL;
	const std::string& tmp = GetName();
//	if(tmp.length() == path_.length())
//	{
	if(!tmp.compare(path_))
	{
		return(this);
	}

//	}
//
	if(tmp.compare(0ul, tmp.length(), path_))
	{
		for(int i = 0, v_size = v.size(); i < v_size; ++i)
		{
			if((ret = v[i]->Find(path_)))
			{
				return(ret);
			}
		}
	}

	return(ret);
}

/************************************ File **********************************/

File::File(const std::string& name_): Component(name_)
{}

File::~File()
{}

void File::Display(int level) const
{
	std::cout << std::string(level, '-') << "[File]" << GetName() << std::endl;
}

const Component* File::Find(const std::string& path_) const
{
	if(!path_.compare(GetName()))
	{
		std::cout << GetName() << std::endl;
		return(this);
	}
	return(NULL);
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

const Component* FindPath(Component* repo_, const std::string& path_)
{

	const Component* tmp = NULL;
	if(!path_.compare(0ul, repo_->GetName().length(), repo_->GetName()))
	{
		tmp = repo_->Find(path_);
	}

	return(tmp);
}


}

