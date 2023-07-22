#ifndef SSHELL_H
#define SSHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h> 
#include <string.h>

void _write(char *str, int stm);
ssize_t write(int fd, const void *buf, size_t count);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void display_prompt(char **av, char **env);


#endif
