#include "holberton.h"
/**
* main - initializes and runs shell
* Return: 0
*/
int main(void)
{
	
	size_t characters, check = -1, bufsize = 1024; char *buffer;
	int i = 0, comsize = 0, c;
	char **commands, **paths;
	extern char **environ;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	paths = set_paths(environ);
	if (isatty(STDIN_FILENO) != 0)
	    write(STDOUT_FILENO, "($) ", 4);
	while ((characters = getline(&buffer, &bufsize, stdin)) != check)
	{
		i = 0;
		while (buffer[i])
			i++;
		if (i == 1)
		{
			if (isatty(STDIN_FILENO) != 0)
				write(STDOUT_FILENO, "($) ", 4);
			continue;
		}
		buffer[i - 1] = '\0';
		comsize = num_elems(buffer, " ");
		commands = set_elems(buffer, " ", comsize);
		c = get_func(commands, environ);
		if (c == 2)
		{
			write(STDOUT_FILENO, "($) ", 4);
			continue;
		}
		if (c == 1 || execute(commands, paths))
		{
			free_coms(commands);
			free(buffer);
			return(0);
		}
		if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "($) ", 4);
		free_coms(commands);
	}
	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	return (0);
}
