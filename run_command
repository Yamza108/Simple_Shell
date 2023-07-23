#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

/**
 * string_length - allocates string
 * @str: string var
 * Return: difference
 */

size_t string_length(const char *str)
{
	const char *ptr = str;

	while (*ptr != '\0')
	{
		ptr++;
	}
	return (ptr - str);
}
/**
 * string_compare - compares two strings
 * @str1: string to cmpare to
 * @str2: string to compare
 * Return: string difference
 */

int string_compare(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * run_command - executes user command
 * @command: var to store user command
 * Return: Nothing
 */

void run_command(char *command)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execlp(command, command, NULL);
		perror("Error executing command\n");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		int status;

		waitpid(pid, &status, 0);
	}
	else
	{
		char error_message[] = "Error forking process\n";

		write(STDERR_FILENO, error_message, string_length(error_message));
	}
}

/**
 * main - takes user input
 * Return: 0 if pass
 */

int main(void)
{
	char *command = NULL;
	size_t command_len = 0;
	ssize_t read_len;

	while (1)
	{
		char prompt[] = "<shell>$ ";

		write(STDOUT_FILENO, prompt, string_length(prompt));

		read_len = getline(&command, &command_len, stdin);
		if (read_len == -1)
		{
			break;
		}
		run_command(command);
	}
	free(command);
	return (0);
}
