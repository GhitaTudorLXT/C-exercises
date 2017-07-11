#include <stdio.h>
#include <stdlib.h>

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

	while (n / base)
	{
		s[len++] = digit_to_alphanum(n % base);

		n /= base;
	}

	s[len++] = digit_to_alphanum(n);

	s[len] = 0;

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
		return 0;

	char s[128];

	itob(atoi(argv[1]), s, atoi(argv[2]));

	printf("%s\n", s);

	return 0;
}