#include "shell.h"

/**
* append_path - add path to command
* @path: path of command
* @command: user command
* Return: command && path if succeded, else null
*/

char *append_path(char *path, char *command)
{
	char *buf;
	size_t a = 0, b = 0;

	if (command == 0)
		command = "";

	if (path == 0)
		path = "";

	buf = malloc(sizeof(char) * (_strlen(path) + _strlen(command) + 2));
	if (!buf)
		return (NULL);

	while (path[a])
	{
		buf[a] = path[a];
		a++;
	}

	if (path[a - 1] != '/')
	{
		buf[a] = '/';
		a++;
	}
	while (command[b])
	{
		buf[a + b] = command[b];
		b++;
	}
	buf[a + b] = '\0';
	return (buf);
}

/**
* find_path - look for path in enviroment
* Return: the path if found, else null.
*/
char *find_path(void)
{
	int i;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && i < 5)
			{
				path++;
				i++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}

/**
* test_path - make sure the path is valid
* @path: tokenized path
* @command: user command
* Return: path + command if true, else null
*/
char *test_path(char **path, char *command)
{
	char *output;
	int a = 0;

	while (path[a])
	{
		output = append_path(path[a], command);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		a++;
	}
	return (NULL);
}
