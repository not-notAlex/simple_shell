#include "holberton.h"
/**
* main - initializes and runs shell
* Return: 0
*/
int main(void)
{
	char *buffer;
	size_t characters, check = -1, bufsize = 1024;
	int i = 0, k = 0, comsize = 0;
	char **commands;
	char **env;
	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	printf("($) ");
	while ((characters = getline(&buffer, &bufsize, stdin)) != check)
	{
		i = 0, k = 0;
		while (buffer[i])
			i++;
		buffer[i - 1] = '\0';
		comsize = num_elems(buffer);
		commands = malloc(sizeof(buffer) * comsize);
		commands = set_elems(buffer, " ", comsize);
		if (execute(commands, env))
			return(0);
		printf("($) ");
		free(commands);
	}
	printf("\n");
	return (0);
}
