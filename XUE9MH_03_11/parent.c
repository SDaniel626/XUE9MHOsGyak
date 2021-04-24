#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Gyerek processz futtatasa: \n");
	system("./child");
	printf("Gyerek processz lefutott!\n");

	return 0;
}
