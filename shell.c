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
	char *buffer;
	char **paths;
	int exit_stat;

	(void)ac;
	signal(SIGINT, sigint_stop);
	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror(av[0]);
		exit(1);
	}
	paths = set_paths(env);
	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "$ ", 2);
	while ((characters = getline(&buffer, &bufsize, stdin)) != check)
	{
		exit_stat = execute_loop(buffer, env, paths, av);
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
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}

/**
 * execute_loop - executes programs/system calls
 * @buffer: input buffer
 * @env: environment variables
 * @paths: paths to check for executables
 * @av: command arguments
 * Return: exit status
 */
int execute_loop(char *buffer, char **env, char **paths, char **av)
{
	int i = 0, comsize = 0, c;
	char **commands, *cpybuf;

	while (buffer[i])
		i++;
	if (i == 1)
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "$ ", 2);
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
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "$ ", 2);
		free_com(commands, cpybuf);
		return (-1);
	}
	if (c == 1 || execute(commands, paths, av, env))
	{
		if (c == 1 && commands[1] != NULL)
		{
			c = _atoi(commands[1]);
			free_com(commands, cpybuf);
			return (c);
		}
		free_com(commands, cpybuf);
		return (0);
	}
	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "$ ", 2);
	free_com(commands, cpybuf);
	return (-1);
}
