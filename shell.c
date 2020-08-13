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
	(void)av;
	signal(SIGINT, sigint_stop);
	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	paths = set_paths(env);
	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "($) ", 4);
	while ((characters = getline(&buffer, &bufsize, stdin)) != check)
	{
		exit_stat = execute_loop(buffer, env, paths);
		if (exit_stat > -1)
			return (exit_stat);
	}
	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
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

	while (buffer[i])
		i++;
	if (i == 1)
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "($) ", 4);
		return (-1);
	}
	buffer[i - 1] = '\0';
	comsize = num_elems(buffer, " ");
	commands = set_elems(buffer, " ", comsize);
	c = get_func(commands, env);
	if (c == 2)
	{
		write(STDOUT_FILENO, "($) ", 4);
		return (-1);
	}
	if (c == 1 || execute(commands, paths))
	{
		free_coms(commands);
		free(buffer);
		if (c == 1 && commands[1] != NULL)
			return (_atoi(commands[1]));
		return (0);
	}
	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "($) ", 4);
	free_coms(commands);
	return (-1);
}
