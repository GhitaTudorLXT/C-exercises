#include <stdio.h>

#define swap(t,x,y) { \
	t aux; \
	aux = x; \
	x = y; \
	y = aux; \
} \

int main()
{
	int a = 5;
	int b = 10;

	swap(int,a,b)

	printf("Should be 10: %d\n", a);
	printf("Should be 5: %d\n", b);

	return 0;
}