#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h> /* wait() */
#include <unistd.h>

int main(int argc, char* argv[])
{
	int pfds[2];
	char buf[30];
	
	if(pipe(pfds) == -1)
	{
		perror("pipe");
		exit(1);
	}

	
	if(!fork())
	{
		printf("CHILD: writing to the pipe\n");
		write((pfds[1]), "test", 5);
		printf("CHILD: exiting\n");
		exit(0);
	}
	else
	{
		printf("PARENT: reading from pipe\n");
		read(pfds[0], buf, 5);
		printf("PARENT: read \"%s\"\n", buf);
		wait(NULL);
	}
	return(0);
}
