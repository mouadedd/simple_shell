#include "shell.h"
/**
 *checker- checks for  built in function
 *@cmd: tokenized input
 *@buf: line drived from getline function
 *
 *Return: 1 cmd executed, else 0
 */
int checker(char **cmd, char *buf)
{
	if (h_builtin(cmd, buf))
		return (1);

	else if (**cmd == '/')
	{
		execute(cmd[0], cmd);
		return (1);
	}
	return (0);
}
