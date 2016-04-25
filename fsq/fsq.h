/****************************************************************************
	fsq
AUTHOR: omer ido                                                  
CREATE DATE: 21/04/16                                              			
DESCRIPTION: 
**************************************************************************/

#ifndef __FSQ_H__
#define __FSQ_H__

#include <boost/thread/recursive_mutex.hpp>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>
#include <boost/noncopyable.hpp>

#include "circ_buf.h"

namespace ilrd
{

template<typename T>
class FSQ : private boost::noncopyable
{
public:
	FSQ(size_t capacity_);
	~FSQ();

	size_t Size();
	bool IsEmpty();
	void Dequeue(T& ret_data_);
	void Remove();
	void Enqueue(const T& data_);

private:
	size_t m_capacity;
	size_t m_size;
	T* circ_q;

	size_t m_head;
	size_t m_tail;

	struct SyncTools;
	SyncTools m_sync_tools;
};

template<typename T>
struct FSQ<T>::SyncTools
{
	SyncTools(size_t capacity_);
	~SyncTools();

	//mutex objects
	boost::recursive_mutex m_consumer_mtx;
	boost::recursive_mutex m_producer_mtx;
	//semaphore objects
	boost::interprocess::interprocess_semaphore m_fill_sem;
	boost::interprocess::interprocess_semaphore m_empty_sem;
};

}
#endif /* ifndef __FSQ_H__*/
