#include "holberton.h"
/**
* _strcpy - malloc and copies string returns pointer to stringmem
* @str: string to be copied
* Return: returns pointer or -1 on fail
*/
char *_strcpy(char *str)
{
	int len = 0, i = 0;
	char *newstr;

	while (str[len])
		len++;
	newstr = malloc(len);
	if (newstr == NULL)
		return (NULL);
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
