class ThreadMutexGuard
{
public:
	// stores a pointer to the lok and acquire the locking
	ThreadMutexGuard(ThreadMutex &lock): lock(&lock)
	{
		acquire();
	}
	
	~ThreadMutexGuard()
	{
		release();
	}
	
	//member functions
	int acquire()
	{
		owner = lock->acquire();
	}
	
	int release()
	{
		// release only if acquired and havent been released it
		if(owner != -1)
		{
			owner = -1;
			return(lock->release());
		}
		else
		{
			return(0);
		}
	}
	
private:
	//pointer to the lock is used to prevent coping or assigning a lock which is erroneous
	ThreadMutex *lock;
	
	// records if the lock is currently held by this object
	int owner;
};


