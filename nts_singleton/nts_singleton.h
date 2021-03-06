/****************************************************************************
	nts_singleton
AUTHOR: omer ido                                                  
CREATE DATE: 13/04/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __NTS_SINGLETON_H__
#define __NTS_SINGLETON_H__

#include <iostream> 

namespace ilrd
{

//class Singleton
//{
//public:
//	static Singleton& Instance() // unique point of access
//	{
//		if(~m_instance)
//		{
//			m_instance = new Singleton;
//		}
//		return m_instance;
//	}
//	// or meyers singleton
//	Singleton& Instance()
//	{
//		static Singleton obj;
//		return obj;
//	}
//
//
//private:
//	Singleton(); //prvent for creating a new Singleton
//	Singleton(const Singleton& other_);
//	Singleton& operator=(const Singleton& other_);
//	~Singleton();
//
//	static Singleton* m_instance; // the one and only instance
//};


template<class T>
class Singleton
{
public:
	static T& GetInst()
	{
		if(! m_instance) // check if NULL, if so, create single Singleton
		{
			m_instance = new T;
			atexit(&Clean);
		}
		return *m_instance;
	}
private:
	static T* m_instance;

	explicit Singleton();
	//  Singleton(const Singleton& other_); 			// no need
	//  Singleton& operator=(const Singleton& other_);
	//	~Singleton();

	static void Clean()
	{
		delete m_instance;
		m_instance = reinterpret_cast<T*>(0xdeadbeef);
	}
};

template<typename T>
T* nts_singleton<T>::m_instance; 	// weak symbol, init to 0 in the data
								 	// segment. if init, it becomes strong symbol. 


class Log
{
public:
	Log(char* str_): m_str(str_)
	{}
	~Log()
	{
		delete[] m_str;
	}
	Log(const Log& other_): m_str(other_.m_str)
	{}
	Log& operator=(const Log& other_)
	{
		m_str = other_.m_str;
		return(*this);
	}

private:
	char* m_str;
};

}
	
#endif /* ifndef __NTS_SINGLETON_H__*/
