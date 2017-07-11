#include <stdio.h>
#include <stdlib.h>

int main()
{
	int buff_size = 1024;
	char *buffer = malloc(buff_size);

	FILE *input = fdopen(0, "r");

	int line_length;

	while ((line_length = getline(&buffer, (size_t*)&buff_size, input)) > 1)
	{
		if (line_length > 80)
			printf("%s\n", buffer);
	}

	fclose(input);
}