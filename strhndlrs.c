#include "holberton.h"
/**
* _strcat - concats string
* @str1: input string1
* @str2: input string2
* @check: checks for adding slash
* Return: returns concatted string
*/
char *_strcat(char *str1, char *str2, int check)
{
	int i, k = 0, size = 0;
	char *nwstr;

	k = _strln(str1);
	size = k + _strln(str2);
	if (check == 1)
		nwstr = malloc(size + 2);
	else
		nwstr = malloc(size + 1);
	if (nwstr == NULL)
		return (NULL);
	for (i = 0; str1[i]; i++)
		nwstr[i] = str1[i];
	if (check == 1)
		nwstr[i] = '/';
	for (i = 0; str2[i]; i++)
	{
		if (check == 1)
			nwstr[i + k + 1] = str2[i];
		else
			nwstr[i + k] = str2[i];
	}
	if (check == 1)
		nwstr[i + k + 1] = '\0';
	else
		nwstr[i + k] = '\0';
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
	return (ind);
}

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 1 if true, 0 if false
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] != str2[i])
		return (0);
	return (1);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
