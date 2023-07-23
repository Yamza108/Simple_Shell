#include "sshell.h"


char *_input()
{
	 char *str = NULL;
	 size_t n = 0;
	
	if (getline(&str, &n, stdin) == -1)
	{
     	perror("Fork failed");
    	free(str);
    	exit(EXIT_FAILURE);
	}
	return (str);
}
