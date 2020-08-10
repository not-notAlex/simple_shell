#include "holberton.h"

char **set_paths(char **env)
{
	int i = 0, k = 0, ar = 0;
	char *str = "PATH=";
	char **paths;
	char *strcpy;

	while(env[i])
	{
		k = 0;
		while(env[i][k])
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
