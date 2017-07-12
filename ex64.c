#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(t,x,y) { \
	t aux; \
	aux = x; \
	x = y; \
	y = aux; \
} \

typedef struct
{
	char *content;
	int occurence;
} word;

char* get_word(char *string)
{
	static char *last;
	static int prev_call = 0;

	char *word;
	char *word_start;
	char place_holder;

	if (string != NULL)
		last = string;

	if (prev_call = 0 && string == NULL)
		return NULL;

	while (*last == ' ' || *last == '\t')
		last++;

	if (*last == 0)
		return NULL;

	word_start = last;

	while (*last != ' ' && *last != '\t' && *last != '\0')
		last++;

	place_holder = *last;
	*last = 0;
	word = (char*)malloc(last - word_start + 1);
	strcpy(word, word_start);

	*last = place_holder;

	prev_call = 1;

	return word;
}

void add_word(word **list, int *size, char *content)
{
	if (*list == NULL || *size == 0)
	{
		*list = (word*)malloc(sizeof(word));
		*size = 1;

		(*(*list)).content = strdup(content);
		(*(*list)).occurence = 1;

		return;
	}

	int i;
	for (i = 0; i < *size; i++)
	{
		if (!strcmp((*list)[i].content, content))
		{
			(*list)[i].occurence++;
			return;
		}
	}

	*list = realloc(*list, (*size + 1) * sizeof(word));

	(*list)[*size].content = strdup(content);
	(*list)[*size].occurence = 1;

	(*size)++;
}

int main()
{
	char *buffer;
	size_t max_size = 4096;
	int actual_size;
	word *words = NULL;
	word a;
	int size = 0;
	int i,j;

	buffer = (char*)malloc(max_size);

	actual_size = getline(&buffer, &max_size, fdopen(0, "r"));

	buffer[actual_size - 1] = 0;

	char *ind_word = get_word(buffer);
	add_word(&words, &size, ind_word);
	free(ind_word);

	while (1)
	{
		ind_word = get_word(NULL);

		if (ind_word == NULL)
			break;

		add_word(&words, &size, ind_word);

		free(ind_word);
	}

	for (i = 0; i < size - 1; i++)
	{
		int max = i;

		for (j = i + 1; j < size; j++)
		{
			if (words[j].occurence > words[max].occurence)
				max = j;
		}

		if (max != i)
		{
			swap(word, words[i], words[max]);
		}
	}

	for (i = 0; i < size; i++)
		printf("%s: %d\n", words[i].content, words[i].occurence);

	free(words);

	return 0;
}