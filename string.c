#include "shell.h"

/**
 * _strlen - returns str lenght
 * @s: str length to check
 * Return: int length of str
 */
int _strlen(char *s)
{
	int a = 0;

	if (!s)
		return (0);

	while (*s++)
		a++;
	return (a);
}

/**
 * _strcmp - perform lexicogarphic comparison between 2 str
 * @s1: 1st str
 * @s2: 2nd str
 * Return: - if 1st str < 2nd str, + if 1st str > 2nd str 
 * and 0 if 1st str == 2nd str
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - needle starts with haystack
 * @needle: find substr 
 * @haystack: search str
 * Return: address proceeding haystack char else NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concat 2 str
 * @scr: buffer src
 * @dest: buffer dest
 * @src: the source buffer
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
