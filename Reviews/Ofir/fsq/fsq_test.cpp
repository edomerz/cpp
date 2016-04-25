#include <iostream>
#include <cstdio>	

#include <boost/thread/recursive_mutex.hpp>				
#include <boost/interprocess/sync/interprocess_semaphore.hpp>				
#include <boost/noncopyable.hpp>	
#include <boost/thread/thread.hpp>

#include "fsq.h"
using namespace ilrd;			

const size_t SLEEP_DURATION_PRODUCER = 5000;	
const size_t SLEEP_DURATION_CONSUMER = 1000;

typedef struct args
{
	FSQ<size_t>& fsq;
	size_t capacity;
} args_t;

size_t number = 1;

boost::mutex Producer_mutex;
boost::mutex Consumer_mutex;

void Producer(void *args)
{
	
	while(1)
	{
		size_t my_num;
		{
			boost::mutex::scoped_lock scoped_lock(Producer_mutex);
		
			my_num = number;
			
			/* source for the modulo: http://stackoverflow.com/a/3803420/3002584 */
			number = (number % (((args_t *)args)->capacity)) + 1;
		}
		
		((args_t *)args)->fsq.Enqueue(my_num);
		
		std::cout << "\ni have written the number: "<< my_num << 
			" (pthread id: " << boost::this_thread::get_id() << ")\n";
	
		std::cout << "\nOCCUPIED SPACE: "<< ((args_t *)args)->fsq.Size() << 
			" (pthread id: " << boost::this_thread::get_id() << ")\n\n";

		usleep(SLEEP_DURATION_PRODUCER);
	}
}	

void Consumer(void *args)
{
	size_t returned_number;
	while(1)
	{
		boost::mutex::scoped_lock scoped_lock(Consumer_mutex);
		((args_t *)args)->fsq.Dequeue(returned_number);
		
		
		std::cout << "\n\t\t\treturned_number: " << returned_number << 
			" (pthread id: " << boost::this_thread::get_id() << ")\n";

		std::cout << "\n\t\t\tOCCUPIED SPACE: "<< ((args_t *)args)->fsq.Size() << 
			" (pthread id: " << boost::this_thread::get_id() << ")\n\n";

		usleep(SLEEP_DURATION_CONSUMER);
	}
}

		
int main()
{
	const size_t capacity = 5;
	FSQ<size_t> fsq(capacity);
	
	args_t args = {fsq, capacity};
	
	const size_t NUM_CONSUMERS = 30;
	const size_t NUM_PRODUCERS = 3;
	
	boost::thread_group consumers_group;
	for(int i = 0; i < NUM_CONSUMERS; ++i)
	{
		consumers_group.create_thread(boost::bind(Consumer, &args)) ;
	}
	
	boost::thread_group producers_group;
	for(int i = 0; i < NUM_PRODUCERS; ++i)
	{
		producers_group.create_thread(boost::bind(Producer, &args)) ;
	}
	
	
	consumers_group.join_all();
	producers_group.join_all();

	
//	boost::thread consumer1_thread(Consumer, &args);
//	boost::thread consumer2_thread(Consumer, &args);
//	boost::thread consumer3_thread(Consumer, &args);
//	boost::thread producer1_thread(Producer, &args);
//	boost::thread producer2_thread(Producer, &args);
//	boost::thread producer3_thread(Producer, &args);
//	boost::thread producer4_thread(Producer, &args);
//	boost::thread producer5_thread(Producer, &args);
//	
//	consumer1_thread.join();
//	consumer2_thread.join();
//	consumer3_thread.join();
//	producer1_thread.join();
//	producer2_thread.join();
//	producer3_thread.join();
//	producer4_thread.join();
//	producer5_thread.join();
	
	
	return(0);
}
