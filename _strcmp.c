#include "main.h"

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
