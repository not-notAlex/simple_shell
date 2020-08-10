#include "holberton.h"

int num_elems(char *buffer)
{
	char *cpybuf, *mand;
	int arraysize = 0;

	cpybuf = _strcpy(buffer);
	mand = strtok(cpybuf, " ");
	while (mand != NULL)
	{
		arraysize++;
		mand = strtok(NULL, " ");
	}
	return (arraysize);
}
