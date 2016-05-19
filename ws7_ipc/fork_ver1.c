#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int rv;
	
	switch(pid = fork())
	{
		case -1:
			perror("fork"); 
			exit(1);
			
		case 0:
			printf("CHILD: this is the child process\n");
			printf("CHILD: my PID is %d\n", getpid());
			printf("CHILD: my parents PID is %d\n", getppid());
			printf("CHILD: enter my exit status (make it small): ");
			scanf(" %d", &rv);
			printf("CHILD: im gone\n");
			exit(rv);
		
		default:
			printf("PARENT: this is the PARENT process\n");
			printf("PARENT: my PID is %d\n", getpid());
			printf("PARENT: my CHILD PID is %d\n", pid);
			printf("PARENT: im now waiting for my child to exit...\n");
			wait(&rv);
			printf("PARENT: my child exit status is: %d\n", WEXITSTATUS(rv));
			printf("PARENT: im outta here\n");
	}
}	
