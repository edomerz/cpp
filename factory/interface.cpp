#include <map>
#include <string>

#include "interface.h"

typedef std::map<std::string, Pfactory> FMAP;
typedef boost::shared_ptr<FMAP> PFMAP;

struct FactorySingleton
{
	static FMAP& Get()
	{
		static FMAP factory_map;
		
		return factory_map;
	}
	
}fs;

Pinterface Interface::Create(const char* name)
{
	std::string n(name);
	
	FMAP::iterator it = fs.Get().Find(n);
	if(it == fs.Get().end())
	{
		throw "unrecognaized type"'
	}
	
	return(it->second->make_me());
}

void interface::register_me(const char* name, Pfactory fac)
{
	fs.Get()[std::string(name)] = fac;
}
