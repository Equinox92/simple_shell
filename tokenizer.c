#include "shell.h"

/**
 * **strtow - splits str into words. Ignores repeat delimiters
 * @d: del str
 * @str: input str
 * Return: point to str array else NULL
 */

char **strtow(char *str, char *d)
{
	char **x;
	int a, b, c, e, wrdno = 0;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
			wrdno++;

	if (wrdno == 0)
		return (NULL);
	x = malloc((1 + wrdno) * sizeof(char *));
	if (!x)
		return (NULL);
	for (a = 0, b = 0; b < wrdno; b++)
	{
		while (is_delim(str[i], d))
			a++;
		c = 0;
		while (!is_delim(str[a + c], d) && str[a + c])
			c++;
		x[b] = malloc((c + 1) * sizeof(char));
		if (!x[b])
		{
			for (c = 0; c < a; c++)
				free(s[c]);
			free(x);
			return (NULL);
		}
		for (e = 0; e < c; e++)
			x[b][c] = str[a++];
		x[b][c] = 0;
	}
	x[b] = NULL;
	return (x);
}

/**
 * **strtow2 - split str into words
 * @d: del str
 * @str: str input
 * Return: point to str array else NULL
 */
char **strtow2(char *str, char d)
{
	char **x;
	int a, b, c, e, wrdno = 0;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
		    (str[a] != d && !str[a + 1]) || str[a + 1] == d)
			wrdno++;
	if (wrdno == 0)
		return (NULL);
	x = malloc((1 + wrdno) * sizeof(char *));
	if (!x)
		return (NULL);
	for (a = 0, b = 0; b < wrdno; b++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		c = 0;
		while (str[a + c] != d && str[a + c] && str[a + c] != d)
			c++;
		x[b] = malloc((c + 1) * sizeof(char));
		if (!x[b])
		{
			for (c = 0; c < b; c++)
				free(x[c]);
			free(x);
			return (NULL);
		}
		for (e = 0; e < c; e++)
			x[b][e] = str[a++];
		x[b][e] = 0;
	}
	x[b] = NULL;
	return (x);
}
