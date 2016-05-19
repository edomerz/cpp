#define _XOPEN_SOURCE

#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
	int segment_id;
	char* shared_memory;
	struct shmid_ds shmbuffer;
	int segment_size;
	const int shared_segment_size = 0x6400; /* 25600 */
	
	/* allocate a shared memory segment */
	segment_id = shmget(IPC_PRIVATE, shared_segment_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	printf("shared memory segment id: %d\n", segment_id);
	
	/* attach the shared memory segment */
	shared_memory = (char*)shmat(segment_id, 0, 0);
	printf("shared memory attached at address %p \n", shared_memory);
	
	/* dedermine the segment size */
	shmctl(segment_id, IPC_STAT, &shmbuffer);
	segment_size = shmbuffer.shm_segsz;
	printf("segment size: %d\n", segment_size);
	
	/* write a string to the shared memory */
	sprintf(shared_memory, "hello world");
	
	/* detach the shared memory */
	shmdt(shared_memory);
	
	/* reatach the shared memory at a different address */
	shared_memory = (char*)shmat(segment_id, (void*)0x5000000, 0);
	printf("shared memory reatached at address %p\n", shared_memory);
	
	/* print out the string from shared memory */
	printf("%s\n", shared_memory);
	
	/* detach the shared memory segment */
	shmdt(shared_memory);
	
	/* deallocate the shared memory segment */
	shmctl(segment_id, IPC_RMID, 0);
	
	return(0);
}
