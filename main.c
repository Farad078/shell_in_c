#include "main.h"

/**
 * main - main program
 * Return: always return 0
 */

int main(void)
{
	size_t n = 10, k;
	char *new = malloc(sizeof(char) * n);
	char **arg, *args, *cmd, d[] = " ";
	int i, counter = 1;

	if (new == NULL)
		return (1);
	printf("$ ");
	getline(&new, &n, stdin);
	k = strlen(new);
	new[k - 1] = '\0';
	cmd = _strcat("/bin/", new);
	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == ' ')
			counter++;
	}
	arg = malloc(sizeof(char *) * counter);
	if (arg == NULL)
		return (2);
	for (i = 0; i <= counter; i++)
	{
		arg[i] = malloc(sizeof(char) * k);
		if (arg[i] == NULL)
			exit(1);
	}
	i = 0;
	args = strtok(cmd, d);
	while (args != NULL)
	{
		arg[i] = args;
		/* printf("%d: %s %p\n", i, args, args);*/
		args = strtok(NULL, d);
		i++;
	}
	arg[i] = NULL;
	if (execve(arg[0], arg, NULL) == -1)
		perror("Error: ");
	return (0);
}
