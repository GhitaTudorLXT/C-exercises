#include <stdio.h>
#include <unistd.h>
#include <float.h>

int main()
{
	unsigned int ui;

	char c;
	unsigned char uc;
	long long int li;

	int i = 0x7F7FFFFF; // setting sign bit to 0 and leaving the last bit of the exponent to 0, otherwise it would be a NAN

	float *fl = (float*)&i;
	printf("Highest float: %f\n", *fl);

	i |= 0x80000000;
	printf("Lowest float: %f\n", *fl); // setting sign bit to 1 for negative numbers

	li = 0x7FEFFFFFFFFFFFFF; // same thing as with i, only this time on 64 bits
	double *d = (double*)&li;
	printf("Highest double: %f\n", *d);

	li |= 0x8000000000000000; // same thing as with the float, only this time on 64 bits
	printf("Lowest double: %f\n", *d);

	i = 0x7FFFFFFF;
	printf("Highest signed integer: %d\n", i);
	printf("Lowest signed integer: %d\n", i + 1);

	ui = 0xFFFFFFFF;
	printf("Highest unsigned integer: %u\n", ui);

	c = 0x7F;

	printf("Highest signed char: %d\n", c);
	printf("Lowest signed char: %d\n", (char)(c + 1));

	uc = 0xFF;
	printf("Highest unsigned char: %d\n", uc);

	return 0;
}