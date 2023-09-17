#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int _putchar(char c);

/* environment variables */
extern char **environ;
void p_env(void);

/* functions to handle strings */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);

/* handle builtins */
int checker(char **cmd, char *buf);
void prompt(void);
void h_signal(int s);
char **ha_tooken(char *line);
int h_builtin(char **command, char *line);

/********h_path.c ***************/
char *append_path(char *path, char *command);
char *find_path(void);
char *test_path(char **path, char *command);

/*functions to handle cmd*/
void exit_cmd(char **command, char *line);
void execute(char *cp, char **cmd);

/* function to free */
void f_buffs(char **buf);

/**
 * struct builtin -struct for the builtin parameters handling
 * @env: First member
 * @exit: Second member
 */
struct builtin
{
	char *env;
	char *exit;
} builtin;

/**
 * struct flags -struct for flags handling
 * @interactive: unique parameter
 */
struct flags
{
	bool interactive;
} flags;

/**
 * struct info -structto get user prompt
 * @final_exit: parameter to exit
 * @ln_count: length
 */
struct info
{
	int final_exit;
	int ln_count;
} info;

#endif
