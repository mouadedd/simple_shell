#include "shell.h"

/**
 * prompt - puts $ prompt to be user friendly
 *
 * Return: 0
 */
void prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;

	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
