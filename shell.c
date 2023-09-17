#include "shell.h"

/**
* main - execute the program
* @ac: argument count
* @av: argument vector
* @envp: environment vector
* Return: 0
*/

int main(int ac, char **av, char *envp[])
{
	size_t buf_size = 0;
	ssize_t line_size = 0;
	char *path = NULL, *path_command = NULL, *line = NULL;
	char **cmd = NULL, **paths = NULL;
	(void)av, (void)envp;

	if (ac < 1)
		return (-1);
	signal(SIGINT, h_signal);
	while (1)
	{
		f_buffs(cmd);
		f_buffs(paths);
		free(path_command);
		prompt();
		line_size = getline(&line, &buf_size, stdin);
		if (line_size < 0)
			break;
		info.ln_count++;
		if (line[line_size - 1] == '\n')
			line[line_size - 1] = '\0';
		cmd = ha_tooken(line);
		if (cmd == NULL || *cmd == NULL || **cmd == '\0')
			continue;
		if (checker(cmd, line))
			continue;

		path = find_path();
		paths = ha_tooken(path);
		path_command = test_path(paths, cmd[0]);
		if (!path_command)
			perror(av[0]);
		else
			execute(path_command, cmd);
	}
	if (line_size < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
