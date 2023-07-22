#include "sshell.h"

void display_prompt(char **av, char **env)
{
	char *str = NULL;
	char *argv[] = {NULL, NULL};
	ssize_t n_chr;
	size_t n = 0;
	int status, i = 0;
	pid_t omomo_pid;
	char error_msg[100];

	while (1)
	{
		write(STDOUT_FILENO, "& ", 2);
		n_chr = getline(&str, &n, stdin);
		if (n_chr == -1)
		{
			perror("Fork failed");
			free(str);
			exit(EXIT_FAILURE);
		}

		while (str[i])
		{
			if (str[i] == '\n')
			{
				str[i] = 0;
			}
			i++;

		}
		argv[0] = str;
		omomo_pid = fork();
		if (omomo_pid == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (omomo_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				sprintf(error_msg, "%s: No such file or directory\n", av[0]);
				write(STDOUT_FILENO, error_msg, strlen(error_msg));
			}
		}
		else 
			wait(&status);

	}
	free(str);

}

