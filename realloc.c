#include "shell.h"

/**
 **_memset - fills memory with constant byte
 *@s: pointer to memory area
 *@b: byte to fill *s with
 *@n: amount of bytes to filled
 *Return: (s) pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = b;
	return (s);
}

/**
 * ffree - free a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates block of memory
 * @ptr: pointer to previous malloc block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: to previous malloc block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *f;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	f = malloc(new_size);
	if (!f)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		f[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (f);
}