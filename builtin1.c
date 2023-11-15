#include "shell.h"

/**
 * _myhistory - display history list, line by line, and
 * numbered starting at 0.
 * @info: Struct with arguments to maintain
 * constant functioning of prototypes.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - set an alias to str
 * @str: str alias
 * @info: parameter struct
 * Return: Always 0 (success) else 1
 */
int unset_alias(info_t *info, char *str)
{
	int c;
	char *a, b;

	d = _strchr(str, '=');
	if (!d)
		return (1);
	b = *a;
	*a = 0;
	c = delete_node_at_index(&(info->alias),
	get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*a = b;
	return (c);
}

/**
 * set_alias - set alias to str
 * @str: str alias
 * @info: parameter structure
 * Return: Always 0 (succes) else 1
 */
int set_alias(info_t *info, char *str)
{
	char *d;

	d = _strchr(str, '=');
	if (!d)
		return (1);
	if (!*++d)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - print alias str
 * @node: alias node
 * Return: Always 0 (success) else 1
 */
int print_alias(list_t *node)
{
	char *e = NULL, *d = NULL;

	if (node)
	{
		e = _strchr(node->str, '=');
		for (e = node->str; e <= d; e++)
			_putchar(*e);
		_putchar('\'');
		_puts(d + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	char *d = NULL;
	int a = 0;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (a = 1; info->argv[a]; i++)
	{
		d = _strchr(info->argv[a], '=');
		if (d)
			set_alias(info, info->argv[a]);
		else
			print_alias(node_starts_with(info->alias, info->argv[a], '='));
	}

	return (0);
}
