class ThreadMutexGuard
{
public:
	// stores a pointer to the lok and acquire the locking
	ThreadMutexGuard(ThreadMutex &lock): lock(&lock)
	{
		owner = lock->acquire();
	}
	
	~ThreadMutexGuard()
	{
		// only release the lock if it was acquired successfully, 
		// -1 failed
		if(owner != -1)
		{
			lock->release();
		}
	}
	
private:
	//pointer to the lock is used to prevent coping or assigning a lock which is erroneous
	ThreadMutex *lock;
	
	// records if the lock is currently held by this object
	int owner;
};


