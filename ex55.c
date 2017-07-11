#include <stdio.h>

char* mstrncpy(char *dest, char *source, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (source[i] == 0)
			break;
		dest[i] = source[i];
	}

	dest[i] = 0;

	return dest;
}

char* mstrncat(char *dest, char *source, int length)
{
	int end_of_dest = 0;
	int i;

	while (dest[end_of_dest] != 0)
		end_of_dest++;

	for (i = 0; i < length; i++)
	{
		if (source[i] == 0)
			break;
		dest[end_of_dest + i] = source[i];
	}

	dest[end_of_dest + i] = 0;

	return dest;
}

int mstrncmp(char *first, char *second, int length)
{
	int i = 0;

	while (first[i] == second[i] && i < length)
	{
		if (first[i] == 0 && second[i] != 0)
			return 1;

		if (first[i] != 0 && second[i] == 0)
			return -1;

		i++;
	}

	if (i == length)
		return 0;

	if (first[i] > second[i]) return -1;

	if (first[i] < second[i]) return 1;
}

int main()
{
	char s[100];

	mstrncpy(s, "haha", 2);

	mstrncat(s, "lalala", 6);

	printf("%s\n", s);

	printf("%d\n", mstrncmp("hahala", "haha", 4));

	return 0;
}