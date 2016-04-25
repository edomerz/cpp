#ifndef __FSQ_H__				
#define __FSQ_H__

#include <cstdio>
#include <iostream>				
				
#include <boost/thread/recursive_mutex.hpp>				
#include <boost/interprocess/sync/interprocess_semaphore.hpp>				
#include <boost/noncopyable.hpp>	
#include <boost/thread/thread.hpp>
#include <boost/atomic.hpp>
			
namespace ilrd				
{					
template<typename T>				
class FSQ : private boost::noncopyable	// disabling copy behavior, since copying an FSQ is expensive			
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
	boost::atomic<size_t> m_atomic_size;					
	T *m_circ_q;			
				
	size_t m_producer;	// used as the producer's FSQ index		
	size_t m_consumer;	// used as the consumer's FSQ index			
				
	struct SyncTools;			
	SyncTools m_sync_tools;			
};				
				
template<typename T>				
struct FSQ<T>::SyncTools				
{				
	SyncTools(size_t capacity_);			
			
	//mutex objects			
	boost::recursive_mutex m_producer_mutex;			
	boost::recursive_mutex m_consumer_mutex;			
	
	//semaphore objects			
	boost::interprocess::interprocess_semaphore m_occupied_space_sem;			
	boost::interprocess::interprocess_semaphore m_free_space_sem;	
};

template <typename T>
FSQ<T>::FSQ(size_t capacity_): 
m_capacity(capacity_), m_atomic_size(0),  m_circ_q(new T[capacity_]), 
m_producer(0), m_consumer(0), m_sync_tools(capacity_)
{}

template <typename T>
FSQ<T>::SyncTools::SyncTools(size_t capacity_): 
m_occupied_space_sem(0), m_free_space_sem(capacity_)
{}

template <typename T>
FSQ<T>::~FSQ()
{
	delete[] m_circ_q;
}

template <typename T>
size_t FSQ<T>::Size()
{
	return (m_atomic_size);
}

template <typename T>
bool FSQ<T>::IsEmpty()
{
	return (!Size());
}

template <typename T>
void FSQ<T>::Enqueue(const T& data_)
{
	/* Waiting on the free_space semaphore:
	If the semaphore value is 0 (= FSQ has zero free space), the calling thread blocks 
	until it can decrement the counter (= until there is a free space to produce onto).
	Else, decrements the free_space_semaphore by 1 (there is one less free space). */
	m_sync_tools.m_free_space_sem.wait();
	
	/* locking the critical section (i.e., the writing into the FSQ, and advancing the
	m_producer index) */
	boost::recursive_mutex::scoped_lock scoped_lock(m_sync_tools.m_producer_mutex);
	
	std::cout << "started Enqueue (pthread id: " << boost::this_thread::get_id() << ")\n";
	
	// writing into the FSQ
	m_circ_q[m_producer] = data_; 
	
	// advancing the m_producer index
	m_producer = (m_producer+1) % m_capacity; // Can we make this atomic, too?

	/* Incrementing m_size by 1. We made it atomic since we experienced weird results when
	 trying to print the size - though their cause is not clear to me */
	m_atomic_size.fetch_add(1);	
	
	// posting: 1 more occupied space
	m_sync_tools.m_occupied_space_sem.post();
	
	std::cout << "finished Enqueue (pthread id: " << boost::this_thread::get_id() << ")\n";

}

template <typename T>
void FSQ<T>::Dequeue(T& ret_data_)		
{	
	/* Waiting on the occupied_space semaphore:
	If the semaphore value is 0 (= FSQ has zero occupied space), the calling thread blocks 
	until it can decrement the counter (= until there is an occupied space to consume from).
	Else, decrements the semaphore by 1 (there is one less occupied space). */
	
	/* Note: Both the Dequeue and the Remove needs to wait on the occupied_space semaphore,
		but on the second hand - waiting on a semaphore in both the Dequeue ITSELF
		and the Remove ITSELF is wrong, because it counts the Consuming twice
		instead of once. Thus, inside Dequeue, we wait & post on the occupied_space_semaphore,
		and inside Remove we wait on the same semaphore, but post to the free_space semaphore. */
	m_sync_tools.m_occupied_space_sem.wait();
	
	boost::recursive_mutex::scoped_lock scoped_lock(m_sync_tools.m_consumer_mutex);
	
	std::cout << "\n\t\t\tstarted Dequeue (pthread id: " << boost::this_thread::get_id() << ")\n";
	
	ret_data_ = m_circ_q[m_consumer]; 
	 
	m_sync_tools.m_occupied_space_sem.post();

	Remove();
}
template <typename T>
void FSQ<T>::Remove()		
{
	/* Waiting on the occupied_space semaphore:
	If the semaphore value is 0 (= FSQ has zero occupied space), the calling thread blocks 
	until it can decrement the counter (= until there is an occupied space to consume from).
	Else, decrements the semaphore by 1 (there is one less occupied space). */
	m_sync_tools.m_occupied_space_sem.wait();
	
	boost::recursive_mutex::scoped_lock scoped_lock(m_sync_tools.m_consumer_mutex);
	
	std::cout << "\n\t\t\tstarted Remove (pthread id: " << boost::this_thread::get_id() << ")\n";
	
	m_consumer = (m_consumer+1) % m_capacity;

	m_atomic_size.fetch_sub(1);
	
	m_sync_tools.m_free_space_sem.post();
}


















				
				
}				
#endif /* fsq.h  */				
