#include "shell.h"

/**
 * f_buffs - free buffers
 * @buf: buffer to free
 * Return: 0
 */
void f_buffs(char **buf)
{
	int a = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[a])
	{
		free(buf[a]);
		a++;
	}
	free(buf);
}
