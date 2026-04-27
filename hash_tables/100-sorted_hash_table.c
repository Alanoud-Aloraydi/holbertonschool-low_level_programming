#include "hash_tables.h"
#include <stdio.h>
#include <string.h>

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: Pointer to the new sorted hash table, or NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * update_snode - Updates a sorted hash node value
 * @node: The node to update
 * @value: The new value
 *
 * Return: 1 on success, 0 on failure
 */
int update_snode(shash_node_t *node, const char *value)
{
	char *copy;

	copy = strdup(value);
	if (copy == NULL)
		return (0);

	free(node->value);
	node->value = copy;
	return (1);
}

/**
 * add_sorted_node - Adds a node to the sorted linked list
 * @ht: The sorted hash table
 * @node: The node to add
 */
void add_sorted_node(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *tmp;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}

	tmp = ht->shead;
	while (tmp != NULL && strcmp(tmp->key, node->key) < 0)
		tmp = tmp->snext;

	if (tmp == ht->shead)
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else if (tmp == NULL)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
	}
	else
	{
		node->snext = tmp;
		node->sprev = tmp->sprev;
		tmp->sprev->snext = node;
		tmp->sprev = node;
	}
}

/**
 * create_snode - Creates a sorted hash node
 * @key: The key
 * @value: The value
 *
 * Return: New node, or NULL
 */
shash_node_t *create_snode(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	node->value = strdup(value);
	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;
	return (node);
}

/**
 * shash_table_set - Adds or updates an element in a sorted hash table
 * @ht: The sorted hash table
 * @key: The key
 * @value: The value
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (node = ht->array[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
			return (update_snode(node, value));
	}

	node = create_snode(key, value);
	if (node == NULL)
		return (0);

	node->next = ht->array[index];
	ht->array[index] = node;
	add_sorted_node(ht, node);
	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: The sorted hash table
 * @key: The key
 *
 * Return: The value, or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	for (node = ht->array[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
	}

	return (NULL);
}

/**
 * print_snode - Prints one sorted hash node
 * @node: The node to print
 * @first: Pointer to first item flag
 */
void print_snode(const shash_node_t *node, int *first)
{
	if (*first == 0)
		printf(", ");

	printf("'%s': '%s'", node->key, node->value);
	*first = 0;
}

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: The sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (node = ht->shead; node != NULL; node = node->snext)
		print_snode(node, &first);
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse
 * @ht: The sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (node = ht->stail; node != NULL; node = node->sprev)
		print_snode(node, &first);
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *tmp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node != NULL)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	free(ht->array);
	free(ht);
}
