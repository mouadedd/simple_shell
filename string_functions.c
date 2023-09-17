#include "shell.h"

/**
 * _strlen - strings length
 * @s: str
 * Return: li
 */
int _strlen(char *s)
{
	int li = 0;

	while (*s != '\0')
	{
		li++;
		s++;
	}

	return (li);
}
/**
 * _strcmp - compare values
 * @s1: input 1
 * @s2: input 2
 *
 * Return: s1[a] - s2[a]
 */
int _strcmp(char *s1, char *s2)
{
	int a;

	a = 0;
	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] != s2[a])
		{
			return (s1[a] - s2[a]);
		}
		a++;
	}
	return (0);
}

/**
 * _strchr - look for a string
 * @s: input
 * @c: input
 * Return: 0
 */
char *_strchr(char *s, char c)
{
	int a = 0;

	for (; s[a] >= '\0'; a++)
	{
		if (s[a] == c)
			return (&s[a]);
	}
	return (0);
}

/**
* _strncmp - compares two strings up to n bytes
* @s1: string 1
* @s2: string 2
* @n: n bytes
* Return: the comparison
*/
int _strncmp(char *s1, char *s2, int n)
{
	int value;

	for (value = 0; s1[value] && s2[value] && value < n; value++)
	{
		if (s1[value] != s2[value])
			return (s1[value] - s2[value]);
	}
	return (0);
}

/**
 * _strdup - duplicate
 * @s: char
 * Return: 0
 */
char *_strdup(char *s)
{
	char *p;
	int l;
	int i;

	if (s == NULL)
	return (NULL);

	l = _strlen(s);

	p = malloc(sizeof(char) * (l + 1));
	if (!p)
		return (NULL);
	for (i = 0; *s != '\0'; s++, i++)
		p[i] = s[0];

	p[i++] = '\0';
	return (p);
}
