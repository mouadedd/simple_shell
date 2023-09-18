#include "shell.h"

/**
 * ha_tooken - create tokens from an input
 * @line: the line to be tokenized
 * Return: array of strings
 */
char **ha_tooken(char *line)
{
	char *buf = NULL, *bufp = NULL, *token = NULL;
	char *delim = " :\t\r\n";
	char **tokens = NULL;
	int token_size = 1;
	size_t ind = 0, flg = 0;

	buf = _strdup(line);
	if (!buf)
		return (NULL);
	bufp = buf;

	while (*bufp)
	{
		if (_strchr(delim, *bufp) != NULL && flg == 0)
		{
			token_size++;
			flg = 1;
		}
		else if (_strchr(delim, *bufp) == NULL && flg == 1)
			flg = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (token_size + 1));
	token = strtok(buf, delim);
	while (token)
	{
		tokens[ind] = _strdup(token);
		if (tokens[ind] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		ind++;
	}
	tokens[ind] = '\0';
	free(buf);
	return (tokens);
}
