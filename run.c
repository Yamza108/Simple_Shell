#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sshell.h"

char *is_in_path(const char *str)
{
    char *store = getenv("PATH");
    char *var_copy = strdup(store);
    char *token = NULL;


    if (var_copy == NULL)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(var_copy, ":");
    while (token != NULL)
    {
        char *filename = strrchr(token, '/'); /* Get the last component (filename) of the path*/
        if (filename != NULL)
            filename++; /* Move past the '/' character*/
        else
            filename = token; /* If there's no '/', use the entire token as the filename*/

        if (strcmp(filename, str) == 0)
        {
            free(var_copy); /* Free the allocated memory before returning*/
            return (token);       /* Return true if the filename matches the input string*/
        }

        token = strtok(NULL, ":"); /* Get the next token*/
    }

    free(var_copy); 
    return (token);       
}

