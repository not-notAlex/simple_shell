#include "holberton.h"

/**
 * print_environment - prints environment
 * @commands: commands to run
 * @env: environment variables
 * Return: no return
 */
void print_environment(char **commands, char **env)
{
	int i = 0, k = 0;

	commands = commands;
	while (env[i])
	{
		k = 0;
		while (env[i][k])
		{
			_putchar(env[i][k]);
			k++;
		}
		_putchar(10);
		i++;
	}
}

/**
 * change_dir - changes directory
 * @commands: commands to run
 * @env: environment variables
 * Return: no return
 */
void change_dir(char **commands, char **env)
{
	char *home = "HOME=";
	int i = 0, k = 0;

	if (commands[1] == NULL)
	{
		while (env[i])
		{
			k = 0;
			while (env[i][k])
			{
				if (env[i][k] != home[k])
					break;
				k++;
			}
			if (k == 5)
				break;
			i++;
		}
		env[i] += 5;
		chdir(env[i]);
		env[i] -= 5;
	}
	else if (_strcmp(commands[1], "-"))
	{
		moveto_oldpwd(env);
	}
	else
		chdir(commands[1]);
}

/**
 * moveto_oldpwd - changes dir to the old pwd
 * @env: environment variables
 * Return: no return
 */
void moveto_oldpwd(char **env)
{
	int i = 0, k = 0, len = 0;
	char *oldpwd = "OLDPWD=";

	while (env[i])
	{
		k = 0;
		while (env[i][k])
		{
			if (env[i][k] != oldpwd[k])
				break;
			k++;
		}
		if (k == 7)
			break;
		i++;
	}
	env[i] += 7;
	len = _strln(env[i]);
	write(STDOUT_FILENO, env[i], len);
	write(STDOUT_FILENO, "\n", 1);
	chdir(env[i]);
	env[i] -= 7;
}
