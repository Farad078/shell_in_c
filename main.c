#include "main.h"

/* function prototype */
void exe(char **a, char **b, char *c);

/**
 * main - main program
 * Return: always return 0
 */

int main(void)
{
	size_t n = 10, k;
	char *new = malloc(sizeof(char) * n);
	char **arg, *args, d[] = " ";
	char *cmd;
	int i, counter = 1;
	char *jst_exit = "/bin/exit";

	if (new == NULL)
		return (1);
	while (true)
	{
		printf("#cisfun$ ");
		getline(&new, &n, stdin);
		k = strlen(new);
		new[k - 1] = '\0';
		for (i = 0; new[i] != '\0'; i++)
		{
			if (new[i] == ' ')
				counter++;
		}
		arg = malloc(sizeof(char *) * counter);
		if (arg == NULL)
		{
			return (2);
		}
		for (i = 0; i <= counter; i++)
		{
			arg[i] = malloc(sizeof(char) * k);
			if (arg[i] == NULL)
				exit(1);
		}
		i = 0;
		cmd = _strcat("/bin/", new);
		args = strtok(cmd, d);
		while (args != NULL)
		{
			arg[i] = args;
			args = strtok(NULL, d);
			i++;
		}
		arg[i] = NULL;
		exe(arg, environ, jst_exit);

	}
	return (0);
}

/**
* exe - check main
* Description: a function that executes the execve program
* @a: a pointer to array of characters
* @b: a pointer to array of characters
* @c: a pointer to character
* Return: Nothing
*/
void exe(char **a, char **b, char *c)
{
	int j;
	pid_t f;

	j = _strcmp(a[0], c);
	if (_strcmp(a[0], "/bin/env") != 0)
		if (j == 1)
		{
			f = fork();
			if (f == 0)
			{
				if (execve(a[0], a, b) == -1)
					perror("Error: ");
			}
			else
				wait(NULL);
		}
		else
			exit(0);
	else
		while (*b != NULL)
		{
			printf("%s\n", *b);
			b++;
		}
}
