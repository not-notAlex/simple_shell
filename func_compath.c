#include "holberton.h"
/**
* num_elems - gets the number of elements
* @buffer: string to get tokens from
* @delim: delimiter
* Return: array size
*/
int num_elems(char *buffer, const char *delim)
{
	char *cpybuf, *mand;
	int arraysize = 0;

	cpybuf = _strcpy(buffer);
	mand = strtok(cpybuf, delim);
	while (mand != NULL)
	{
		arraysize++;
		mand = strtok(NULL, delim);
	}
	return (arraysize);
}
/**
* set_elems - sets elements in the array
* @buffer: input buffer
* @delim: input delimiter
* @n: size of array
* Return: array
*/
char **set_elems(char *buffer, const char *delim, int n)
{
	char *cpybuf, *mand, **elems;
	int i = 0;

	cpybuf = _strcpy(buffer);
	mand = strtok(cpybuf, delim);
	elems = malloc(sizeof(mand) * (n + 1));
	while (mand != NULL)
	{
		elems[i] = mand;
		mand = strtok(NULL, delim);
		i++;
	}
	elems[i] = NULL;
	return (elems);
}
/**
* set_paths - sets the path variable
* @env: enviroment variables to pull path from
* Return: path
*/
char **set_paths(char **env)
{
	int i = 0, k = 0, ar = 0;
	char *str = "PATH=";
	char **paths;
	char *strcpy;

	while (env[i])
	{
		k = 0;
		while (env[i][k])
		{
			if (env[i][k] != str[k])
				break;
			k++;
		}
		if (k == 5)
			break;
		i++;
	}
	env[i] += 5;
	strcpy = _strcpy(env[i]);
	ar = num_elems(strcpy, ":");
	paths = set_elems(strcpy, ":", ar);
	return (paths);
}
/**
* free_coms - frees the coms
* @command: the commands to be freed
*/
void free_coms(char **command)
{
	free(command);
}
