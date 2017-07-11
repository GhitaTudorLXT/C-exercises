#include <stdio.h>

int lower (int c)
{
	return c >= 'A' && c <= 'Z' ? c + ('a' - 'A') : c;
}

int main()
{
	printf("%d\n", lower(65));

	return 0;
}