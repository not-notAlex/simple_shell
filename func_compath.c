#include "holberton.h"
/**
* num_elems - gets the number of elements
* @buffer: string to get tokens from
* @delim: delimiter
* Return: array size
*/
int num_elems(char *buffer, const char *delim)
{
	char *mand;
	int arraysize = 0;

	mand = strtok(buffer, delim);
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
	char *mand, **elems;
	int i = 0;

	mand = strtok(buffer, delim);
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
	char *strcpy, *str = "PATH=";
	char **paths;

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
	free(strcpy);
	strcpy = _strcpy(env[i]);
	paths = set_elems(strcpy, ":", ar);
	env[i] -= 5;
	free(strcpy);
	return (paths);
}
/**
* free_com - frees the com and the cpybuf
* @loca: the commands to be freed
* @tion: the cpybuf to be freed
*/
void free_com(char **loca, char *tion)
{
	free(loca);
	free(tion);
}
/**
 * _atoi - converts string into an int
 * @str: string to convert
 *
 * Return: resulting number
 */
int _atoi(char *str)
{
	int i, total = 0;

	for (i = 0; str[i]; i++)
	{
		total *= 10;
		total += (str[i] - 48);
	}

	return (total);
}
