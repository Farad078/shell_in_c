#include "main.h"

/**
 * _strcmp - check main
 * Description: a function that compares two strings
 * @str1: a pointer to a string
 * @str2: a pointer to a string
 * Return: returns 0 (succeeds) or 1 if it fails.
 */

int _strcmp(char *str1, char *str2)
{
	int i, len, counter = 0;

	len = strlen(str2);
	for (i = 0; i < len; i++)
	{
		if (str1[i] == str2[i])
		{
			counter++;
		}
		else
			break;
	}

	if (counter == len)
		return (0);
	else
		return (1);
}
