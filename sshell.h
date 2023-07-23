#ifndef SSHELL_H
#define SSHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h> 
#include <string.h>

void _write(char *str, int stm);
void display_prompt(char **av, char **env);
int _execute(char *argv, char **ar);
char **_tokenizer(char *ab, char *delim);
void prompt(void);
char *_input();



#endif
