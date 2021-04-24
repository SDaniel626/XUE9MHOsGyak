#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int status = 7;
	pid_t pid;
	if((pid = fork()) < 0)
		perror("Fork error");
	else
		if(pid  == 0)
			exit(status);

	waitpid(pid,&status,0);

	if(wait(&status) != pid)
		perror("wait error");
	if(WIFEXITED(status))
		printf("Normalis befejozedes, visszaadott ertek: %d\n",WEXITSTATUS(status));

	if((pid = fork()) < 0)
		perror("fork error");
	else
		if(pid == 0)
			abort();

	waitpid(pid,&status,0);

	if(wait(&status) != pid)
		perror("wait error");
	if(WIFSIGNALED(status))
		printf("Abnormalis befejezodes, a szignal sorszama: %d\n",WTERMSIG(status));

}
