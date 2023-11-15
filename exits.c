#include "shell.h"

/**
 **_strncpy - copies str
 *@src: src str
 *@dest: dest str to write to
 *@n: no. of characters to copy
 *Return: concat. str
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *a = dest;
	int b, c;

	b = 0;
	while (src[b] != '\0' && b < n - 1)
	{
		dest[b] = src[b];
		b++;
	}
	if (b < n)
	{
		c = b;
		while (c < n)
		{
			dest[c] = '\0';
			c++;
		}
	}
	return (a);
}

/**
 **_strncat - concat 2 str
 *@dest: 1st str
 *@src: 2nd str
 *@n: no. of bytes to use
 *Return: concat. str
 */
char *_strncat(char *dest, char *src, int n)
{
	char *a = dest;
	int b, c;

	b = 0;
	c = 0;
	while (dest[b] != '\0')
		b++;
	while (src[c] != '\0' && c < n)
	{
		dest[b] = src[c];
		b++;
		c++;
	}
	if (c < n)
		dest[b] = '\0';
	return (a);
}

/**
 **_strchr - locates a char in str
 *@c: char to find
 *@s: str to parse
 *Return: (s) a pointer to mem. area 
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
