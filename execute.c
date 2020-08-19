#include "holberton.h"
/**
* execute - starts a child proccess to execute the command
* @commands: command to be excuted
* @paths: array of paths to execute upon
* @argv: command arguments
* @env: environment varibales
* Return: on error
*/
int execute(char **commands, char **paths, char **argv, char **env)
{
	pid_t my_exid;
	int status = 0, i = 0;

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
				path_execute(paths, commands, argv, i, env);
				i++;
			}
		else if (execve(commands[0], commands, env) == -1)
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

/**
 * print_error - prints an error
 * @argv: command arguments
 * @commands: commands to run
 * Return: no return
 */
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

/**
 * path_execute - executes commands for paths
 * @path: paths to check
 * @commands: commands to execute
 * @argv: command arguments
 * @i: index of loop
 * @env: environment veriables
 * Return: no return
 */
void path_execute(char **path, char **commands, char **argv, int i, char **env)
{
	char *path_command;
	struct stat st;

	path_command = _strcat(path[i], commands[0], 1);
	if (stat(path_command, &st) == 0)
	{
		if (execve(path_command, commands, env) == -1)
			perror(argv[0]);
		return;
	}
	if (path[i + 1] == NULL)
	{
		if (isatty(STDIN_FILENO) != 0)
			perror(argv[0]);
		else
			print_error(argv, commands);
	}
	free(path_command);
}
