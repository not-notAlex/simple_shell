#include "holberton.h"

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
	return elems;
}
