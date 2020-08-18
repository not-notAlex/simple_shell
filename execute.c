#include "holberton.h"
/**
* execute - starts a child proccess to execute the command
* @commands: command to be excuted
* @paths: array of paths to execute upon
* Return: on error
*/
int execute(char **commands, char **paths, char **argv)
{
	pid_t my_exid;
	int status = 0, i = 0;
	char *path_command;
	struct stat st;

	my_exid = fork();
	if (my_exid == -1)
	{
		perror(argv[0]);
		return (0);
	}
	if (my_exid == 0)
	{
		if (no_slash(commands[i]))
			while (paths[i])
			{
				path_command = _strcat(paths[i], commands[0], 1);
				if (stat(path_command, &st) == 0)
				{
					if (execve(path_command, commands, NULL) == -1)
						perror(argv[0]);
					break;
				}
				i++;
				if (paths[i] == NULL)
				{
					if (isatty(STDIN_FILENO) != 0)
						perror(argv[0]);
					else
						print_error(argv, commands);
				}
				free(path_command);
			}
		else if (execve(commands[0], commands, NULL) == -1)
		{
			if (isatty(STDIN_FILENO) != 0)
				perror(argv[0]);
			else
				print_error(argv, commands);
		}
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

void print_error(char **argv, char **commands)
{
	char *str;
	int len;

	str = _strcat(argv[0], ": 1: ", 0);
	str = _strcat(str, commands[0], 0);
	str = _strcat(str, ": not found\n", 0);
	len = _strln(str);
	write(STDERR_FILENO, str, len);
	free(str);
}
