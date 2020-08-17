#include "holberton.h"
/**
* execute - starts a child proccess to execute the command
* @commands: command to be excuted
* @paths: array of paths to execute upon
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
		return (0);
	}
	if (my_exid == 0)
	{
		if (no_slash(commands[i]))
			while (paths[i])
			{
				path_command = _strcat(paths[i], commands[0]);
				if (stat(path_command, &st) == 0)
				{
					if (execve(path_command, commands, NULL) == -1)
						perror("Error:");
					break;
				}
				i++;
				if (paths[i] == NULL)
				{
					perror("Error:");
				}
				free(path_command);
			}
		else if (execve(commands[0], commands, NULL) == -1)
			perror("Error:");
		free(path_command);
		return (1);
	}
	wait(&status);
	return (0);
}

/**
 * no_slash - determines if command has a slash
 * @str: string to check
 *
 * Return: 1 if true 0 if false
 */
int no_slash(char *str)
{
	int i;

	while (str[i])
	{
		if (str[i] == '/')
			return (0);
		i++;
	}
	return (1);
}
