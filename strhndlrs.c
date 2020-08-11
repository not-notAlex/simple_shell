#include "holberton.h"
/**
* _strcat - concats string
* @str1: input string1
* @str2: input string2
* Return: returns concatted string
*/
char *_strcat(char *str1, char *str2)
{
	int i, k = 0, size = 0;
	char *nwstr;

	k = _strln(str1);
	size = k + _strln(str2);
	printf("%d", size);
	nwstr = malloc(size + 2);

	for (i = 0; str1[i]; i++)
		nwstr[i] = str1[i];
	nwstr[i] = '/';
	for (i = 0; str2[i]; i++)
		nwstr[i + k + 1] = str2[i];

	nwstr[i + k + 1] = '\0';
	return (nwstr);
}
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
/**
* _strln - gets the length of a string
* @str: input string
* Return: returns amount of characters
*/
int _strln(char *str)
{
	int ind;

	for (ind = 0; str[ind] != '\0'; ind++)
		continue;
	printf("%d", ind);
	return (ind);
}
