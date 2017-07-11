#include <stdio.h>

unsigned int setbits (unsigned int x, unsigned int p, unsigned int n, unsigned int y)
{
	unsigned int deletemask;
	unsigned int fromy;
	unsigned int tox;

	fromy = (1 << n) - 1; // setting mask for grabbing bits from y

	deletemask = fromy; //initializing deletemask for later use

	fromy = y & fromy; // getting bits from y

	tox = fromy << p; // bits from y shifted to the correct position for insertion

	deletemask = ~deletemask; // inverting delete mask (1 in the most significant, 0 in the less significant)
	deletemask = deletemask << p; // shifting the zeros to match the insertion interval
	deletemask = deletemask + (1 << p) - 1; // setting the rightmost zeros to ones

	x = x & deletemask; // deleting the bits
	x = x | tox; // inserting the bits

	return x;
}

int main()
{
	printf("%d\n", setbits(128,0,1,127));
}