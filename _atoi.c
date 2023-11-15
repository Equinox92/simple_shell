#include "shell.h"

/**
 * interactive - returns 1 if shell is interactive
 * @info: struct address
 * Return: 1 if interactive else 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - is char a delimiter
 * @delim: the delimeter string
 * @c: char to check
 * Return: 1 if true else 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - alphabetic character check
 *@c: char to input
 *Return: 1 if alphabetic else 0 
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts str to int
 *@s: str to convert
 *Return: 0 for no int in str else convert to int
 */
int _atoi(char *s)
{
	int a, sin = 1, flg = 0, out;
	unsigned int rslt = 0;

	for (a = 0;  s[a] != '\0' && flg != 2; a++)
	{
		if (s[a] == '-')
			sin *= -1;

		if (s[a] >= '0' && s[a] <= '9')
		{
			flg = 1;
			rslt *= 10;
			rslt += (s[a] - '0');
		}
		else if (flg == 1)
			flg = 2;
	}

	if (sin == -1)
		out = -rslt;
	else
		out = rslt;

	return (out);
}
