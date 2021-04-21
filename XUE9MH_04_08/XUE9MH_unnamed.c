#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd[2];
	char buf;

	if(pipe(fd) < 0)
		perror("pipe"),exit(EXIT_FAILURE);

	if(fork() == 0)
	{
		close(fd[0]);

		write(fd[1],"SD XUE9MH",10);

		close(fd[1]);

		exit(EXIT_SUCCESS);
	}

	close(fd[1]);

	printf("ezt a szoveget kuldte a gyerek: ");
	while(read(fd[0],&buf,1)>0)
		printf("%c",buf);
	printf("\n");

	close(fd[0]);

	exit(EXIT_SUCCESS);
}
