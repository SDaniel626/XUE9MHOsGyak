#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	if((pid = fork()) < 0)
	{
		perror("Fork error");
	} else
		if(pid == 0)
			execl("./child","child",(char*)NULL);
	waitpid(pid,NULL,0);
}
