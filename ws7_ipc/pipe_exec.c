#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int pfds[2];

	if(pipe(pfds) == -1)
	{
		perror("pipe");
		exit(1);
	}

	if(!fork())// child process
	{
		close(1); 		// close normal stdout
		dup(pfds[1]); 	// make stdout same as pfds[1] the dub will get fd 1
		close(pfds[0]); // no need for it
		execlp("ls", "ls", NULL);
	}
	else 	// parent
	{
		close(0); 		// close normal stdin
		dup(pfds[0]);	// make stdin same as pfsd[0]
		close(pfds[1]);
		execlp("wc", "wc", "-l", NULL);
	}
	return(0);
}

