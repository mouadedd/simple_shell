#include "shell.h"

/**
 * h_builtin - handle builtin functions
 * @command: tokenized commands
 * @line: input
 * Return: 1 if true, else 0
 */
int h_builtin(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*command, builtin.env) == 0)
	{
		p_env();
		return (1);
	}
	else if (_strcmp(*command, builtin.exit) == 0)
	{
		exit_cmd(command, line);
		return (1);
	}
	return (0);
}

/**
 *h_signal- handle signals
 *@s: signal
 *Return: 0
 */

void h_signal(int s)
{
	(void)s;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
