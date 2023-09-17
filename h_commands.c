#include "shell.h"

/**
 * execute - execute the command of users
 *@cp: command
 *@cmd: array of pointers to commands
 * Return: 0
 */
void execute(char *cp, char **cmd)
{
	pid_t child_pid;
	char **env = environ;
	int status;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);

	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		f_buffs(cmd);
		exit(98);
	}
	else
		wait(&status);
}

/**
* exit_cmd - exit command
* @command: tokenized command
* @line: input read from stdin
* Return: 0
*/

void exit_cmd(char **command, char *line)
{
	free(line);
	f_buffs(command);
	exit(0);
}
