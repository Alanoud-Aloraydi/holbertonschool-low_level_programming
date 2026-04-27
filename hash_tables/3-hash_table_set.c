#include "hash_tables.h"
#include <string.h>

/**
 * update_node - Updates the value of an existing node
 * @node: The node to update
 * @value: The new value
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int update_node(hash_node_t *node, const char *value)
{
	char *val_copy;

	val_copy = strdup(value);
	if (val_copy == NULL)
		return (0);

	free(node->value);
	node->value = val_copy;

	return (1);
}

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table
 * @key: The key
 * @value: The value
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	for (node = ht->array[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
			return (update_node(node, value));
	}

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);

	node->key = strdup(key);
	node->value = strdup(value);
	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (0);
	}

	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
