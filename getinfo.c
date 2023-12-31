#include "shell.h"

/**
 * clear_info - init. info_t struct
 * @info: struct addr.
 */
void clear_info(info_t *info)
{
	info->argc = 0;
	info->arg = NULL;
	info->path = NULL;
	info->argv = NULL;
}

/**
 * set_info - init. info_t struct
 * @info: struct addr.
 * @av: arg. vector
 */
void set_info(info_t *info, char **av)
{
	int a = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (a = 0; info->argv && info->argv[a]; a++)
			;
		info->argc = a;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - free info_t fields
 * @info: struct addr.
 * @all: true if fields freed
 */
void free_info(info_t *info, int all)
{
	info->argv = NULL;
	info->path = NULL;
	ffree(info->argv);
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
