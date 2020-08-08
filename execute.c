#include "holberton.h"
/**
* execute - starts a child proccess to execute the command
* @commands: command to be excuted
* Return: on error
*/
void execute(char **commands)
{
	pid_t my_exid;
	int status;

	my_exid = fork();
	if (my_exid == -1)
	{
		perror("Error:");
		return;
	}
	if (my_exid == 0)
	{
		if (execve(commands[0], commands, NULL) == -1)
		{
			perror("Errror:");
			return;
		}
	}
	wait(&status);
}
