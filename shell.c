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
	char **commands, **paths;
	extern char **environ;



	buffer = (char *)malloc(bufsize * sizeof(char));

	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	paths = set_paths(environ);
	printf("($) ");
	while ((characters = getline(&buffer, &bufsize, stdin)) != check)
	{
		i = 0, k = 0;
		while (buffer[i])
			i++;
		buffer[i - 1] = '\0';
		comsize = num_elems(buffer, " ");
		commands = set_elems(buffer, " ", comsize);
		if (check_sys(commands) && execute(commands, paths))
		{
			free_coms(commands);
			free(buffer);
			return(0);
		}

		printf("($) ");
		/*free_coms(commands);*/
	}
	printf("\n");
	free(buffer);
	return (0);
}
