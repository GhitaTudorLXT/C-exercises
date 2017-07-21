#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define MAXLEN 1024

int readlines(char *file, char **lineptr, int maxlines)
{ 
	int len, nlines;
	char *p, *line;

	FILE *input = NULL;

	size_t max_size = MAXLEN;

	line = (char*)malloc(MAXLEN);

	nlines = 0;
	input = fopen(file, "r");

	if (input == NULL)
	{
		printf("Error opening file\n");
		return -1;
	}

	while ((len = getline(&line, &max_size, input)) > 0)
	{
		line[len-1] = '\0';  /* delete newline */
		strcpy(lineptr[nlines++], line);

		if (nlines == maxlines) break;
	}

	fclose(input);

	return nlines;
}

int sreadlines(char *file, char **lineptr, int maxlines)
{
	int len, nlines;
	char *p, *line;

	FILE *input;

	size_t max_size = MAXLEN;

	line = (char*)malloc(MAXLEN);

	nlines = 0;
	input = fopen(file, "r");

	if (input == NULL)
	{
		printf("Error opening file\n");
		return -1;
	}

	while ((len = getline(&line, &max_size, input)) > 0)
	{
		line[len - 1] = '\0';

		p = (char*)malloc(len);
		strcpy(p, line);
		lineptr[nlines++] = p;

		if (nlines == maxlines) break;
	}

	fclose(input);

	return nlines;
}

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Usage: ./ex57 [filename] [linecount]\n");
		return 0;
	}

	int i;
	int line_count = atoi(argv[2]);
	int actual_line_count;

	struct timeval start, stop;

	char **lines = (char**)malloc(line_count * sizeof(char*));

	for (i = 0; i < line_count; i++)
	{
		lines[i] = (char*)malloc(MAXLEN);
		if (lines[i] == NULL)
			printf("NULL allocation\n");
	}

	gettimeofday(&start, NULL);
	readlines(argv[1], lines, line_count);
	gettimeofday(&stop, NULL);

	printf("Fast: %f\n", (stop.tv_sec - start.tv_sec) * 1000 + (float)(stop.tv_usec - start.tv_usec) / 1000);

	for (i = 0; i < line_count; i++)
		free(lines[i]);

	gettimeofday(&start, NULL);
	sreadlines(argv[1], lines, line_count);
	gettimeofday(&stop, NULL);

	printf("Slow: %f\n", (stop.tv_sec - start.tv_sec) * 1000 + (float)(stop.tv_usec - start.tv_usec) / 1000);

	/* Uncomment to print lines

	for (i = 0; i < actual_line_count; i++)
		printf("%s\n", lines[i]);

	*/

	return 0;
}