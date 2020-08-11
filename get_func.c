#include "holberton.h"

void get_func(char **commands, char **env)
{
	int i = 1;

	sys_coms sys[] = {
		{"env", &print_environment},
		{NULL, NULL}
	};

	if (_strcmp(commands[0], sys[0].coms))
	    sys[0].f(env);

	while(sys[i].f != NULL)
	{
		if (_strcmp(commands[0], sys[i].coms))
			sys[i].f(commands);
		i++;
	}
}
