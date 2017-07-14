#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void* mcalloc(unsigned int obj_count, unsigned int size)
{
	void *mem = NULL;
	unsigned int total_size = obj_count * size;
	int i;

	mem = malloc(total_size);

	if (!mem)
		return NULL;

	for (i = 0; i < total_size; i++)
		((uint8_t*)mem)[i] = 0;

	return mem;
}

int main()
{
	char *s = mcalloc(1024, sizeof(char));

	strcpy(s, "Text");

	printf("%s\n", s);

	return 0;
}