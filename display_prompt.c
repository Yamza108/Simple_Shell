#include "sshell.h"

void main()
{
	char *str = NULL;
	char **argv = NULL;
	ssize_t n_char;
	size_t n = 0;
	int status, i = 0;
	pid_t child_pid;
	char *delim = " \n";

	while (1)
	{
		prompt();
		str = _input();
		argv = _tokenizer(str, delim);
		_execute(argv[0], argv);
		
		free(str);
		free(argv);
	}

}


