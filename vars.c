#include "shell.h"

/**
 * is_chain - test current char in buffer is chain delimeter
 * @info: parameter struct
 * @buf: char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, else 0
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - checks if continue chaining based on last status
 * @info: parameter struct
 * @buf: char buffer
 * @p: address of current position in buf
 * @i: start position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - replaces aliases in token string
 * @info: parameter struct
 *
 * Return: 1 placed, else 0
 */
int replace_alias(info_t *info)
{
	int x;
	list_t *node;
	char *p;

	for (x = 0; x < 10; x++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replaces vars in token string
 * @info: parameter struct
 *
 * Return: 1 if replaced, else 0
 */
int replace_vars(info_t *info)
{
	int x = 0;
	list_t *node;

	for (x = 0; info->argv[x]; x++)
	{
		if (info->argv[i][0] != '$' || !info->argv[x][1])
			continue;

		if (!_strcmp(info->argv[x], "$?"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[x]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[x][1], '=');
		if (node)
		{
			replace_string(&(info->argv[x]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[x], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces a string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, else 0
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}