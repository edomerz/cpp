#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <boost/shared_ptr.hpp>

class Interface;
typedef boost::shared_ptr<Interface> Pinterface;

class Factory
{
public:
	virtual Pinterface make_me() = 0;
};

typedef boost::shared_ptr<Factory> Pfactory;

template<class S>
class GenericFactory : public Factory
{
public:
	virtual Pinterface make_me()
	{
		Pinterface p(new S());
		
		return p;
	}
};

class Interface
{
public:
	virtual ~Interface() 
	{}
	
	virtual void DoSomething() = 0;
	
	static Pinterface Create(const char* name);
	
	static void register_me(const char* name, Pfactory fac);
};

template<class S>
class RegisterFactory
{
public:
	RegisterFactory(const char* name)
	{
		Pfactory pf(new GenericFactory<S>);
		
		Interface::register_me(name, pf);
	}
	
	#define REGISTER_INTERFACE(NAME, TYPE) namespace{ static RegisterFactory<type> fac(name);};
};

#endif // __INTERFACE_H__

