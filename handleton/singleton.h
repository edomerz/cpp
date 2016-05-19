#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>
#include <cstdlib>		//atexit


namespace ilrd
{

template<typename T>
class Singleton
{
public:
	Singleton();		// new version, to enable Handleton<Counter> cnt;
	static T& GetInst();
private:
	static void CleanUp();
	
	static T* inst;
	
//	Singleton(); 
	~Singleton();
	Singleton(const Singleton& );
	const Singleton& operator=(const Singleton& );
};

template<typename T>
Singleton<T>::Singleton()
{
	GetInst();
}

#ifndef __INSTANCE__
template<typename T>
T* Singleton<T>::inst = 0;

template<typename T>
T& Singleton<T>::GetInst()
{
	if(!inst)
	{
		inst = new T();
		atexit(&CleanUp);
	}
	
	return(*inst);
}

template<typename T>
void Singleton<T>::CleanUp()
{
	delete inst;
	inst = reinterpret_cast<T*>(0xdeadbeef);
}
#endif // __INSTANCE__

}

#endif // __SINGLETON_H__
