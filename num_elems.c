#include "holberton.h"
/**
* num_elems - gets the number of elements
* @buffer: string to get tokens from
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
