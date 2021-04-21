#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main()
{
	int fd;
	char buf;

	if(mkfifo("XUE9MH", 0666) < 0)
		perror("mkfifo"),exit(EXIT_FAILURE);

	if(fork() == 0)
	{
		fd = open("XUE9MH",O_WRONLY);

		write(fd,"Simon Daniel",13);

		close(fd);

		exit(EXIT_SUCCESS);
	}

	fd = open("XUE9MH",O_RDONLY);

	printf("Ezt a szoveget kuldte a gyerek: ");
	while(read(fd,&buf,1) > 0)
		printf("%c",buf);
	printf("\n");

	close(fd);

	wait(NULL);

	unlink("XUE9MH");

	exit(EXIT_SUCCESS);
}
