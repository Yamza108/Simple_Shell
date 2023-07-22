#include "sshell.h"

void display_prompt(char **av, char **env)
{
	char *str = NULL; 
	char *argv[] = {NULL, NULL};
       	char error_msg[100];
	ssize_t n_chr;
	size_t n = 0;
	int status, i = 0;
	pid_t child_pid;
	
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
		if (n_chr == '\0')
			break;

		while (str[i])
		{
			if (str[i] == '\n')
			{
				str[i] = 0;
			}
			i++;

		}
		argv[0] = str;
		child_pid = fork();
		if (child_pid == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
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

