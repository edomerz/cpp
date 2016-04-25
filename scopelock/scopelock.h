/****************************************************************************
	scopelock
AUTHOR: omer ido                                                  
CREATE DATE: 18/04/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __SCOPELOCK_H__
#define __SCOPELOCK_H__
							
#include<iostream>				
#include<pthread.h>				
				
				
namespace ilrd				
{				
				
				
struct TRY_LOCK{};				
struct DONT_LOCK{};				
				
				
//the ScopeLock is a generic lock for scope behaviour and controlling a resource				
//for critical synchronization code				
template<typename T>				
class ScopeLock				
{				
public:				
				
	explicit ScopeLock(T& mutex__); //must enter a mutex			
	explicit ScopeLock(T& mutex__, const TRY_LOCK& type_try_); 			
	explicit ScopeLock(T& mutex__, const DONT_LOCK& type_dont_);			
				
	~ScopeLock();			
				
	//Interface MEMBER functions			
	//explicitly lock the resource			
	void Lock();			
	//explicitly unlock the resource			
	void Unlock();			
	//try to lock the resource			
	bool TryLock();			
				
	//member function getter - IsLocked  			
	bool IsLocked() const;			
				
private:				
	//resource raw pointer			
	T& m_mutex;			
	//is the mutex owned			
	bool m_is_locked;			
				
	//disable copyable behaviour			
	ScopeLock(const ScopeLock& other_);			
	ScopeLock& operator=(const ScopeLock& other_);			
				
};				

#endif /* ifndef __SCOPELOCK_H__*/
