#include "holberton.h"
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
