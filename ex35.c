#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ONE 49

char digit_to_alphanum(int x)
{
	if (x - 9 > 0)
		return 'A' + x - 10;
	return x + 48;
}

void itob(int n, char *s, int base)
{
	int len = 0;
	int i;

	if (base == 1)
	{
		memset(s, ONE, n);
		s[n] = '\0';

		return;
	}

	while (n / base)
	{
		s[len++] = digit_to_alphanum(n % base);

		n /= base;
	}

	s[len++] = digit_to_alphanum(n);

	s[len] = '\0';

	for (i = 0; i < len / 2; i++)
	{
		char aux = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = aux;
	}
}

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Usage: ./ex35 [number] [base]\n");

		return 0;
	}

	int number, base;

	char s[128];

	number = atoi(argv[1]);
	base = atoi(argv[2]);

	if (base < 1 || base > 36)
	{
		printf("[base] should be in range [1, 36]\n");
		return 0;
	}

	itob(atoi(argv[1]), s, atoi(argv[2]));

	printf("%s\n", s);

	return 0;
}