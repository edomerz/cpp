#define _GNU_SOURCE /* needed for struct sigaction */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void sigint_handler(int sig)
{
	/* POSIX says that write() is async-safe (so is
safe to call from within the handler), while printf() is not.
	*/
	write(0, "ahh SIGINT!\n", 14);
}

int main()
{
/*	void sigint_handler(int sig);  prototype */
	
	char s[200];
	struct sigaction sa;
	
	sa.sa_handler = sigint_handler; /* assign the signal handler function */
	
	/*sa.sa_flags = 0;*/ /* or SA_RESTART */
	sa.sa_flags = SA_RESTART; 
	sigemptyset(&sa.sa_mask);
	
	if(sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(1);
	}
	
	printf("enter a string:\n");
	if(fgets(s, sizeof(s), stdin) == NULL)
	{
		perror("fgets");
	}
	else
	{
		printf("u entered: %s\n", s);
	}
	
	return(0);
}