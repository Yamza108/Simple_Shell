#include "sshell.h"

int _execute(char *argv, char **ar)
{
pid_t child_pid;
int status = 0;
 child_pid = fork();
	if (child_pid == -1)
		{
			free(ar);
			exit(EXIT_FAILURE);
    }
	if (child_pid == 0)
          {
              if (execve(argv, ar, NULL) == -1)
              {
                  perror(" No such file or directory\n");
			  }
		  }
 	else             
		wait(&status);
	return (0);

}




char **_tokenizer(char *ab, char *delim)
{

char **store = NULL;
int i = 0;
char *dup;

if (!ab)
	exit(0);

store = malloc(sizeof(char*) * (strlen(ab)+ 1));
if (!store)
{
	exit(0);
}
i = 0;
dup = strtok((ab), delim);
	
	while (dup)
	{
		store[i] = malloc(sizeof(char) * (strlen(dup) + 1));
		strcpy(store[i], (dup));
		i++;
		dup = strtok(NULL, delim);

	}
	store[i] = NULL;
	return (store);
}
