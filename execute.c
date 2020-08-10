#include "holberton.h"
/**
* execute - starts a child proccess to execute the command
* @commands: command to be excuted
* Return: on error
*/
int execute(char **commands, char **paths)
{
	pid_t my_exid;
	int status = 0, i = 0;
	char *path_command;
	struct stat st;

	my_exid = fork();
	if (my_exid == -1)
	{
		perror("Error:");
		return;
	}
	if (my_exid == 0)
	{
		if (no_slash(commands[i]))
			while(paths[i])
			{
				path_command = _strcat(paths[i], commands[0]);
				if (stat(path_command, &st) == 0)
					if (execve(path_command, commands, NULL) == -1)
						perror("Error:");
				i++;
				free(path_command);
			}
		else if(execve(commands[0], commands, NULL) == -1)
			perror("Error:");
		return (1);
	}
	else
		wait(&status);
	return (0);
}

int no_slash(char *str)
{
	int i;

	while(str[i])
	{
		if (str[i] == '/')
			return (0);
		i++;
	}
	return (1);
}
