#include "main.h"
/**
 * main - main program
 * Return: always return 0
 */
int main(void)
{
	size_t n = 10, k;
	char *new = malloc(sizeof(char) * n);
	char **arg, *args, d[] = " ";
	int i, counter = 1;
	pid_t f;

	if (new == NULL)
		return (1);
	while (true)
	{
		printf("#cisfun$ ");
		getline(&new, &n, stdin);
		k = strlen(new);
		new[k - 1] = '\0';
		for (i = 0; new[i] != '\0'; i++)
			if (new[i] == ' ')
				counter++;
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
		args = strtok(new, d);
		while (args != NULL)
		{
			arg[i] = args;
			/* printf("%d: %s %p\n", i, args, args);*/
			args = strtok(NULL, d);
			i++;
		}
		arg[i] = NULL;
		f = fork();
		if (f == 0)
		{
			if (execve(arg[0], arg, NULL) == -1)
				perror("Error: ");
		}
		else
			wait(NULL);
	}
	return (0);
}
