#ifndef __NON_THREAD_SAFE_SINGLETON_H__
#define __NON_THREAD_SAFE_SINGLETON_H__

#include <iostream>
#include <cstdlib> // atexit
#include <cstdio>
namespace ilrd
{
	template <class T>
	class Singleton
	{
	public:
		/* 'static' here means: the user may call it without instantiating ITS OWN 
	   	singleton-type class */
		static T& GetInstance(); 
								  
	private:
		explicit Singleton(); // we want nobody to instantiate a Singletone
		static T* instance_ptr;
		static void Clean();
	};
	
	template <class T>
	T* Singleton<T>::instance_ptr = NULL;
	
	
	
	template <class T>
	T& Singleton<T>::GetInstance()
	{
		/* 'static' here means: the object is constructed only once through
		the lifetime of the program */
		/* note that this instantiate T, not class Singleton */

		if (!instance_ptr)
		{
			instance_ptr = new T();
			atexit(&Clean);
		}
		if (instance_ptr == reinterpret_cast<T*>(0xdeadbeef))
			printf("buuuuu\n");
		return (*instance_ptr);
	}
	
	template <class T>
	void Singleton<T>::Clean()
	{
		delete instance_ptr;
		instance_ptr = reinterpret_cast<T*>(0xdeadbeef);
		
	}
	
	

} // namespace ilrd
#endif // __NON_THREAD_SAFE_SINGLETONE_H__
