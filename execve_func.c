#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void execve_func(char **buffer, struct stat *statbuf, char **envp)
{
	int *argc;
	char **argv[];
	char **exe;
	char *delim = " ";

	argv = strtok(buffer, delim );

	execve(arg[0], argv, envp);

	perror("Error: (execve)\n");
	exit(EXIT_FAILURE);
}
