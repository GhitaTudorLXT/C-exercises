#include <stdio.h>

#define TOTAL_LENGTHS 1024

int iswhitespace(char c)
{
	if (c == '\n' || c == ' ' || c == '\t')
	{
		return 1;
	}

	return 0;
}

int main()
{
	char c;
	int word_lengths[TOTAL_LENGTHS] = {0};
	int lower_limit = 0;
	int upper_limit = 0;
	int char_counter;

	int ext;
	int i,j;

	ext = 0;
	while (!ext)
	{
		ext = 1;

		char_counter = 0;
		while ((c = getchar()) != EOF)
		{
			
			if (!iswhitespace(c))
			{
				char_counter++;
			}
			else
			{
				ext = 0;
				break;
			}
		}

		if (!ext)
			word_lengths[char_counter]++;
	}

	i = 0;
	while (word_lengths[i] == 0)
		i++;
	lower_limit = i;

	while (i < TOTAL_LENGTHS)
	{
		if (word_lengths[i] != 0)
			upper_limit = i;
		i++;
	}

	printf("Lower limit: %d\n", lower_limit);
	printf("Upper limit: %d\n", upper_limit);

	for (i = lower_limit; i <= upper_limit; i++)
	{
		printf("%d ", i);
		for (j = word_lengths[i]; j > 0; j--)
			printf("|");
		printf("\n");
	}

	return 0;
}