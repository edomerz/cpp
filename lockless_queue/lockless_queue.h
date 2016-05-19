/****************************************************************************
	lockless_queue
AUTHOR: omer ido                                                  
CREATE DATE: 18/05/16                                              			
DESCRIPTION: thread safe without using os synchronization
because, there is only 1 thread writing, and only 1 thread reading
each has its own pointer to an array of pointer to objects
and only allowed to change his pointer
**************************************************************************/
#ifndef __LOCKLESS_QUEUE_H__
#define __LOCKLESS_QUEUE_H__

#include <iostream> 

namespace ilrd
{
class LocklessQueue
{
public:
	/* size of the array is a power of 2 */
	LocklessQueue(unsigned int size): m_size(1 << size), m_mask(m_size - 1),
										m_head(0), m_tail(0), m_empty(false),
										m_queue(new unsigned char*[m_size])
	{}
	~LocklessQueue()
	{
		delete[] *m_queue;
	}

	void Push(unsigned char *buffer)
	{
		if(((m_head + 1) & m_mask) == m_tail)
		{
			m_empty = false;
		}
		else
		{
			m_queue[m_head] = buffer;
			m_head = (m_head + 1) & m_mask;
			m_empty = true;
		}
	}
	char* Pop()
	{
		if(m_empty || (m_head == m_tail))
		{
			return(NULL);
		}

		unsigned char *buffer = m_queue[m_tail];
		m_tail = (m_tail + 1) & m_mask;
		if(m_tail == m_head)
		{
			m_empty = true;
		}

		return(buffer);
	}

private:
	int m_size;
	int m_mask;
	int m_head;
	int m_tail;
	bool m_empty;
	
	LocklessQueue& LocklessQueue(const LocklessQueue& other_);
	LocklessQueue& operator=(const LocklessQueue& other_);

	unsigned char **m_queue;
};

}
#endif /* ifndef __LOCKLESS_QUEUE_H__*/
