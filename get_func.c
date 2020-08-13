#include "holberton.h"

/**
 * get_func - gets and runs appropriate system function
 * @commands: commands to execute
 * @env: environment variables
 * Return: 0 if not syscom, 1 if exit, 2 if syscom
 */
int get_func(char **commands, char **env)
{
	int i = 0;

	sys_coms sys[] = {
		{"env", &print_environment},
		{"cd", &change_dir},
		{NULL, NULL}
	};

	if (_strcmp(commands[0], "exit"))
		return (1);

	while (sys[i].f != NULL)
	{
		if (_strcmp(commands[0], sys[i].coms))
		{
			sys[i].f(commands, env);
			return (2);
		}
		i++;
	}
	return (0);
}
