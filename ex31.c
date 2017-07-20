#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int binsearch(int x, int *v, int len)
{
	int low;
	int high;
	int mid;

	low = 0;
	high = len - 1;

	while (low != high - 1)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid;
		else low = mid;
	}

	if (x == v[low])
		return low;
	if (x == v[high])
		return high;

	return -1;
}


int sbinsearch(int x, int v[], int n) 
{ 
   int low, high, mid; 
   low = 0; 
   high = n - 1; 
   while (low <= high) {
       mid = (low+high)/2; 
       if (x < v[mid]) 
           high = mid + 1; 
       else if (x  > v[mid]) 
           low = mid + 1; 
       else     
           return mid; 
   } 
   return -1; 
}


int main(int argc, char**argv)
{
	if (argc < 3)
	{
		printf("\n Usage: ./ex31 [filename] [number]\n\n");
		return 0;
	}

	int n;
	int *v;
	int result;

	struct timeval start, stop;

	FILE *f = fopen(argv[1], "r");

	fscanf(f, "%d", &n);

	v = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		fscanf(f, "%d", &v[i]);

	gettimeofday(&start, NULL);
	sbinsearch(atoi(argv[2]), v, n);
	gettimeofday(&stop, NULL);

	printf("Time for slow binsearch: %f miliseconds\n\n", (stop.tv_sec - start.tv_sec) * 1000 + (float)(stop.tv_usec - start.tv_usec) / 1000);

	gettimeofday(&start, NULL);
	binsearch(atoi(argv[2]), v, n);
	gettimeofday(&stop, NULL);

	printf("Time for binsearch: %f miliseconds\n", (stop.tv_sec - start.tv_sec) * 1000 + (float)(stop.tv_usec - start.tv_usec) / 1000);

	return 0;
}