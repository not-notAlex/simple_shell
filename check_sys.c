#include "holberton.h"
/**
* check_sys - checks if command is a local command
* @commands: input command
* Return: 1 or 0
*/
int check_sys(char **commands)
{
	char *ex = "exit";
	int i = 0;

	while (ex[i])
	{
		if (ex[i] != commands[0][i])
			return (0);
		i++;
	}
	if (commands[0][i] == '\0')
		return (1);
	return (0);
}
