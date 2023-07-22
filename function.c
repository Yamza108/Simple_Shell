#include "sshell.h"

/**
 * 
 *
 *
 *
 *
 *
 */

void _write(char *str, int stm)
{
	int i = 0;
	for (; str[i]; i++)
	{
		write(stm, &str[i], 1);
	}
}
