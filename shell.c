#include "holberton.h"
/**
* main - initializes and runs shell
* @ac: unused num arguments
* @av: unused array of args
* @env: environment variables
* Return: 0
*/
int main(int ac, char **av, char **env)
{
	size_t characters, check = -1, bufsize = 1024;
	char *buffer, *strcpy;
	char **paths;
	int exit_stat;

	(void)ac;
	(void)av;
	signal(SIGINT, sigint_stop);
	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	paths = set_paths(env, strcpy);
	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "($) ", 4);
	while ((characters = getline(&buffer, &bufsize, stdin)) != check)
	{
		exit_stat = execute_loop(buffer, env, paths);
		if (exit_stat > -1)
		{
			free(buffer);
			free(paths);
			return (exit_stat);
		}
	}
	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	free(paths);
	return (0);
}

/**
 * sigint_stop - stops program from closing on signal
 * @sig_num: signal for ctrl+c
 *
 * Return: no return
 */
void sigint_stop(int sig_num)
{
	(void)sig_num;
	signal(SIGINT, sigint_stop);
	write(STDOUT_FILENO, "\n($) ", 5);
	fflush(stdout);
}

/**
 * execute_loop - executes programs/system calls
 * @buffer: input buffer
 * @env: environment variables
 * @paths: paths to check for executables
 * Return: exit status
 */
int execute_loop(char *buffer, char **env, char **paths)
{
	int i = 0, comsize = 0, c;
	char **commands;
	char *cpybuf;

	while (buffer[i])
		i++;
	if (i == 1)
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "($) ", 4);
		return (-1);
	}
	buffer[i - 1] = '\0';
	cpybuf = _strcpy(buffer);
	comsize = num_elems(cpybuf, " ");
	free(cpybuf);
	cpybuf = _strcpy(buffer);
	commands = set_elems(cpybuf, " ", comsize);
	c = get_func(commands, env);
	if (c == 2)
	{
		write(STDOUT_FILENO, "($) ", 4);
		free(commands);
		free(cpybuf);
		return (-1);
	}
	if (c == 1 || execute(commands, paths))
	{
		if (c == 1 && commands[1] != NULL)
		{
			c = _atoi(commands[1]);
			free(commands);
			free(cpybuf);
			return (c);
		}
		free(commands);
		free(cpybuf);
		return (0);
	}
	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "($) ", 4);
	free(commands);
	free(cpybuf);
	return (-1);
}
