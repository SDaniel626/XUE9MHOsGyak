#include <stdio.h>
#include <stdlib.h>

int main()
{
	if(!system("dir"))
	{
		printf("\ndir hivas mukodik\n");
	}

	system("nemletezoparancs");

	return 0;
}

