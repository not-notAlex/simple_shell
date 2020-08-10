#include "holberton.h"
/**
* execute - starts a child proccess to execute the command
* @commands: command to be excuted
* Return: on error
*/
int execute(char **commands, char **env)
{
	pid_t my_exid;
	int status = 0;

	my_exid = fork();
	if (my_exid == -1)
	{
		perror("Error:");
		return;
	}
	if (my_exid == 0)
	{
		if (execve(commands[0], commands, env) == -1)
		{
			perror("Error:");
			return (1);
		}
	}
	else
		wait(&status);
	return (0);
}
