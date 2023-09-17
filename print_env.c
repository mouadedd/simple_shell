#include "shell.h"

/**
* p_env - prints the environment
* Return: 0
*/

void p_env(void)
{
	int a = 0;
	char **env = environ;

	while (env[a])
	{
		write(STDOUT_FILENO, (const void *)env[a], _strlen(env[a]));
		write(STDOUT_FILENO, "\n", 1);
		a++;
	}
}
