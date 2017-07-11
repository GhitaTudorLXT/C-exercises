#include <stdio.h>
#include <string.h>

int any(char *string, char *chars)
{
	int i,j;

	for (i = 0; i < strlen(string); i++)
		for (j = 0; j < strlen(chars); j++)
		{
			if (string[i] == chars[j])
				return i;
		}

	return -1;
}

int main(int argc, char **argv)
{
	if (argc < 3) return 0;

	int result = any(argv[1], argv[2]);

	if (result != -1)
		printf("First match at location %d\n", result);
	else
		printf("No match\n");

	return 0;
}