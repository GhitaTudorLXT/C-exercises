#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

typedef struct hash_list hash_list;

struct hash_list
{
	char *name;
	char *def;
	struct hash_list *next;
};

static hash_list *hash_table[HASHSIZE];

unsigned int hash (char *s)
{
	unsigned int hashval = 0;

	for (; s != '\0'; s++)
		hashval = *s + 31 * hashval;

	return hashval % HASHSIZE;
}

hash_list* lookup (char *name)
{
	unsigned int index = hash(name);

	hash_list *iterator;

	for (iterator = hash_table[index]; iterator != NULL; iterator = iterator->next)
		if (!strcmp(iterator->name, name))
			return iterator;

	return NULL;
}

hash_list* install (char *name, char *def)
{
	unsigned int hashval;
	hash_list *new_node;

	new_node = lookup(name);

	if (new_node)
	{
		free(new_node->def);
		new_node->def = strdup(def);
	}

	else
	{
		new_node = (hash_list*)malloc(sizeof(hash_list));
		new_node->name = strdup(name);
		new_node->def = strdup(def);

		hashval = hash(name);
		new_node->next = hash_table[hashval];
		hash_table[hashval] = new_node;
	}

	return new_node;
}

int undef(char *name)
{
	hash_list *node;
	hash_list *iterator;
	unsigned int hashval;

	hashval = hash(name);

	node = lookup(name);

	if (!node)
		return -1;

	iterator = hash_table[hashval];

	if (iterator == node)
	{
		free(hash_table[hashval]);
		hash_table[hashval] = NULL;

		return 0;
	}

	while (iterator->next != node) iterator = iterator->next;

	iterator->next = node->next;

	free(node);

	return 0;
}

int main()
{
	hash_list hn;

	return 0;
}