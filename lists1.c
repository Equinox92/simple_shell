#include "shell.h"

/**
 * list_len - checks length of list
 * @h: point to 1st node
 * Return: list size
 */
size_t list_len(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * list_to_strings - returns string array (list->str)
 * @head: point to 1st node
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t a = list_len(head), b;
	char **strar;
	char *str;

	if (!head || !a)
		return (NULL);
	stra = malloc(sizeof(char *) * (a + 1));
	if (!strar)
		return (NULL);
	for (a = 0; node; node = node->next, a++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; b < a; b++)
				free(strar[b]);
			free(strar);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strar[a] = str;
	}
	strar[a] = NULL;
	return (strar);
}


/**
 * print_list - print elements of the linked list
 * @h: point to 1st node
 * Return: list size
 */
size_t print_list(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * node_starts_with - return node with string prefix
 * @prefix: str match
 * @node: point to list head
 * @c: the next character after prefix to match
 * Return: match else null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *d = NULL;

	while (node)
	{
		d = starts_with(node->str, prefix);
		if (d && ((c == -1) || (*d == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - fetch node index
 * @node: point to node
 * @head: point to list head
 * Return: node index else -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t a = 0;

	while (head)
	{
		if (head == node)
			return (a);
		head = head->next;
		a++;
	}
	return (-1);
}
