#include "main.h"

/**
 * _strcat - check main.h
 * Description: concatenate strings
 * @a: a pointer to string
 * @b: a pointer to string
 * Return: return a pointer to string.
 */


char *_strcat(char *a, char *b)
{
	size_t len1 = strlen(a);
	size_t len2 = strlen(b);
	size_t len = len1 + len2;
	size_t i = 0, j = 0;
	char *temp = malloc(sizeof(char) * len);

	if (temp == NULL)
	{
		exit(1);
	}

	while (i < len1)
	{
		temp[i] = a[i];
		i++;
		j++;
	}
	i = 0;

	while (i < len2)
	{
		temp[j] = b[i];
		i++;
		j++;
	}
	return (temp);
}
