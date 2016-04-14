#ifndef __NON_THREAD_SAFE_SINGLETON_H__
#define __NON_THREAD_SAFE_SINGLETON_H__

#include <iostream>

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
	};
	
	template <class T>
	T& Singleton<T>::GetInstance()
	{
		/* 'static' here means: the object is constructed only once through
		the lifetime of the program */
		/* note that this instantiate T, not class Singleton */
		static T singelton_instance;
		
		return (singelton_instance);
	}

} // namespace ilrd
#endif // __NON_THREAD_SAFE_SINGLETONE_H__
