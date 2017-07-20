#include <stdio.h>
#include <string.h>

int lower (int c)
{
	return c >= 'A' && c <= 'Z' ? c + ('a' - 'A') : c;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage: ./ex210 [string]\n");
		return 0;
	}

	int i;

	for (i = 0; i < strlen(argv[1]); i++)
	{
		argv[1][i] = lower(argv[1][i]);
	}

	printf("%s\n", argv[1]);

	return 0;
}