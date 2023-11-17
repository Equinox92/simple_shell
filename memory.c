#include "shell.h"

/**
 * bfree - free pointer & NULL the address
 * @ptr: pointer address to free
 * Return: 1 freed else 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

