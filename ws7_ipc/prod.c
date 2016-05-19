#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <string.h>

#define SIZE 0x6400

typedef struct String
{
	int offset;
	char text[1];
}String;

void ReadShm(String* str)
{
	printf("PROD: %s\n", str->text);
}

void WriteShm(String* str, const char* input)
{
	memcpy((void*)&str->text[str->offset], input, strlen(input));
}

int main(int argc, char* argv[])
{
	int segment_id = 0;
	String* str = 0;
	int segment_size = 0;
	struct shmid_ds shmbuf;
	int shm_segment_size = SIZE;

	/* key */
	key_t key;
	key = ftok(".", 'a');

	printf("key: %d\n", key);

	/*scanf("%d", &segment_id);*/

	/* Acquire the allocated shared memory */
	shmget(key, shm_segment_size, IPC_CREAT | S_IRUSR | S_IWUSR);

	/* attach the shared memory */
	str = (String*)shmat(segment_id, 0, 0);

	shmctl(segment_id, IPC_STAT, &shmbuf);
	segment_size = shmbuf.shm_segsz;
	printf("PROD: segment size: %d\n", segment_size);

	/* read shared memory */
	printf("PROD: read\n %s\n", str->text);

	/* write to shared memory */
	memcpy((void*)&str->text[str->offset], " prod: Ping", 11);


	/* detach shared memory */
	shmdt(str);

	/* deallocate shared memory */
	shmctl(segment_id, IPC_RMID, 0);

	return(0);
}
