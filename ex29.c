#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned int x)
{
	int count = 0;

	while (x)
	{
		x &= x - 1;
		count++;
	}

	return count;
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return 0;

	printf("%u\n", bitcount((unsigned int)atoi(argv[1])));

	return 0;
}