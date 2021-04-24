#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	char cmd[50];
	do {
		scanf("%s",cmd);
		system(cmd);
	}while(1);

	return 0;
}
