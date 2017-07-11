/* 
* NOT FINISHED
*/

#include <stdio.h>
#include <unistd.h>
#include <float.h>

#define LOWEST_INCREMENT 1.0/32

int main()
{
	int i = 0x7F7FFFFF;//0x3F400000;
	float *fl = (float*)&i;

	printf("%f\n", *fl);

	return 0;

	float f = FLT_MAX;
	float increment = (1 << 30) * 1024.0;
	
	while (increment > LOWEST_INCREMENT)
	{
		while (f < FLT_MAX)
		{
			f += increment;
		}
		printf("Overflow: %f\n", f);

		f -= increment;

		printf("Highest point for increment %f: %f\n", increment, f);

		increment /= 2;
	}

	return 0;
}