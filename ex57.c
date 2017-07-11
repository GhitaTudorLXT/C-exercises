#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

int readlines(char **lineptr, int maxlines)
{ 
	int len, nlines;
	char *p, *line;

	line = (char*)malloc(MAXLEN);

	size_t max_size = MAXLEN;

	nlines = 0;

	while ((len = getline(&line, &max_size, fdopen(0, "r"))) > 0)
	{
		line[len-1] = '\0';  /* delete newline */
		strcpy(lineptr[nlines++], line);

		if (nlines == maxlines) break;
	}

	return nlines;
}

int main(int argc, char**argv)
{
	if (argc < 2)
		return 0;

	int i;
	int line_count = atoi(argv[1]);
	int actual_line_count;

	char **lines = (char**)malloc(line_count);

	for (i = 0; i < line_count; i++)
		lines[i] = (char*)malloc(MAXLEN);

	actual_line_count = readlines(lines, line_count);

	printf("Lines: %d\n", actual_line_count);

	for (i = 0; i < actual_line_count; i++)
		printf("%s\n", lines[i]);

	return 0;
}