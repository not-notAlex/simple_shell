#include "holberton.h"

char *_strcat(char *str1, char *str2)
{
	int i, k = 0, size = 0;
	char *newstr;

	for (k = 0; str1[k]; k++)
		size++;
	for (i = 0; str2[i]; i++)
		size++;

	newstr = malloc(size + 2);

	for(i = 0; str1[i]; i++)
		newstr[i] = str1[i];
	newstr[i] = '/';
	for(i = 0; str2[i]; i++)
		newstr[i + k + 1] = str2[i];

	newstr[i + k + 1] = '\0';
	return (newstr);
}
