#include "holberton.h"
/**
* main - initializes and runs shell
* Return: 0
*/
int main(void)
{
	char *buffer, *cpybuf, *mand;
	size_t characters, check = -1, bufsize = 1024;
	int i = 0, k = 0, arraysize = 0;
	char **commands;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	printf("($) ");
	while ((characters = getline(&buffer, &bufsize, stdin)) != check)
	{
		arraysize = 0, i = 0, k = 0;
		while (buffer[i])
			i++;
		buffer[i - 1] = '\0';
		cpybuf = _strcpy(buffer);
		mand = strtok(cpybuf, " ");
		while (mand != NULL)
		{
			arraysize++;
			mand = strtok(NULL, " ");
		}
		commands = malloc(sizeof(mand) * arraysize);
		cpybuf = _strcpy(buffer);
		mand = strtok(cpybuf, " ");
		while (mand != NULL)
		{
			commands[k] = mand;
			mand = strtok(NULL, " ");
			k++;
		}
		execute(commands);
		printf("($) ");
		free(commands);
		free(cpybuf);
	}
	return (0);
}
