/****************************************************************************
	singleton
AUTHOR: omer ido                                                  
CREATE DATE: 02/05/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream> 
#include <cstdlib> 		// atexit
#include <boost/core/noncopyable.hpp> 	

namespace ilrd
{

template<typename T>
class Singleton : private boost::noncopyable
{
public:
	static volatile T*& GetIns();
	
	
private:
//	static volatile T* ins;
	
	explicit Singleton();
	~Singleton();
	Singleton(const Singleton& );
	
	static void Clean();

	static pthread_mutex_t mtx;
}

//template<typename T>
//T* Singleton::ins = 0;

template<typename T>
static volatile T*& Singleton<T>::GetIns()
{
	static volatile T* ins = 0;

	T* tmp = ins;
	// memory barrier, hard sequence point.
	if(!ins)	
	{
		//lock lock - only one will have accesses, and only for the first time
		pthread_mutex_lock(&mtx);
		if(!ins)
		{
			tmp = new volatile T(); // creates memory space, 
									// ctor a Singleton object, and make tmp point to that space
									
			// another memory barrier as a hard sequence point, to make sure line 51 is finished
			ins = tmp;
			
			atexit(&Clean);
		}
		// unlock lock
		pthread_mutex_unlock(&mtx);
	}
	return(tmp);
}

//static void Singleton::Clean()
//{
//	delete ins;
//	ins = reinterpret_cast<T*>0xdeadbeef;
//}
static void Singleton::Clean()
{
	delete GetIns();
	GetIns() = reinterpret_cast<T*>0xdeadbeef;
}

}
	
#endif /* ifndef __SINGLETON_H__*/
