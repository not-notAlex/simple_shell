#include "holberton.h"

char *_strcpy(char *str);
void execute(char **commands);

int main()
{
	char *buffer, *cpybuf;
	size_t bufsize = 1024;
	size_t characters;
	int i = 0, k = 0;
	char **commands;
	char *mand;
	int arraysize = 0;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	printf("($) ");
	while(characters = getline(&buffer, &bufsize, stdin) != -1)
	{
		arraysize = 0;
		i = 0;
		k = 0;
		while(buffer[i])
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
	return(0);
}

char *_strcpy(char *str)
{
	int len = 0, i = 0;
	char *newstr;

	while (str[len])
		len++;
	newstr = malloc(len);
	while(str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

void execute(char **commands)
{
	pid_t my_pid;
	int status;

	my_pid = fork();
	if (my_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (my_pid == 0)
	{
		if (execve(commands[0], commands, NULL) == -1)
		{
			perror("Error:");
			return;
		}
	}
	wait(&status);
}
