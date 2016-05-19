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
	char text[SIZE];
}String;

int main()
{
	/* process */
	pid_t pid;
	int rv;									/* return value of the child process */
	
	/* uniq key */
	key_t key;

	/* shared memory segment */
	int segment_id;
	struct shmid_ds shmbuffer;
	String *str = 0;
/*	char* shared_memory = 0;*/
	int segment_size;
	const int shared_segment_size = SIZE; /* 25600 B */
	
	/* generate a uniq key using ftok */
	key = ftok(".", 'a');
	printf("key: %d\n", key);

	/* allocate a shared memory segment */
	/*segment_id = shmget(IPC_PRIVATE, shared_segment_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);*/
	segment_id = shmget(key, shared_segment_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	printf("segment id: %d", segment_id);
	
	/* Determine the segment size */
	shmctl(segment_id, IPC_STAT, &shmbuffer); /* will this work before attachment ? YES */
	segment_size = shmbuffer.shm_segsz;
	printf("segment size is %d\n", segment_size);
	
	/* fork */
	switch(pid = fork())
	{
		case -1:
			perror("fork"); 
			exit(1);
			
		case 0:
			;
			char quit = 0;
			const char c_str[] = "Ping";
			printf("CHILD: this is the child process\n");
			printf("CHILD: my PID is %d\n", getpid());
			printf("CHILD: my parents PID is %d\n", getppid());
/*			printf("CHILD: enter my exit status (make it small): ");*/
/*			scanf(" %d", &rv);*/
			rv = 1;

			str = (String*)shmat(segment_id, 0, 0);
			printf("CHILD: shared memory attached at address %p \n", (void*)str);

			printf("segment id is: %d\n", segment_id);

			printf("CHILD: len %lu\n", strlen(c_str));

/*			sprintf(str->text, c_str);*/
/*			sprintf((char*)(str + 4), "ping");*/
			memcpy((void*)&(str->text[str->offset]), (void*)c_str, strlen(c_str));
			str->offset += strlen(c_str);
			
			printf("CHILD: text %s\n", str->text);
			printf("CHILD: offset %d\n", str->offset);
			
			printf("enter 'q' to quit\n");
			scanf("%c", &quit);
			while(quit != 'q')
			{}
			/* shared memory detach */
			shmdt(str);
			
			/* deallocate the shared memory */
			shmctl(segment_id, IPC_RMID, 0);
			

			
			printf("CHILD: im gone\n");
			exit(rv);
		
		default:
			;
			const char p_str[] = "Pong";
			printf("PARENT: this is the PARENT process\n");
			printf("PARENT: my PID is %d\n", getpid());
			printf("PARENT: my CHILD PID is %d\n", pid);
			printf("PARENT: im now waiting for my child to exit...\n");
			
			str = (String*)shmat(segment_id, 0, 0);
			printf("PARENT: shared memory attached at address %p \n", (void*)str);
			
			wait(&rv);
						
/*			sprintf(str->text[str->offset], p_str);*/
			memcpy((void*)&(str->text[str->offset]), (void*)p_str, strlen(p_str));
			str->offset += strlen(p_str);
			
			printf("PARENT: %s\n", str->text);
			
			printf("PARENT: my child exit status is: %d\n", WEXITSTATUS(rv));
			
			/* detach memory segment */
			shmdt(str);
			
			/* deallocate memory segment */
			shmctl(segment_id, IPC_RMID, 0);
			
			printf("PARENT: im outta here\n");
	}
}	
