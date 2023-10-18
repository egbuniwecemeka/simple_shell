#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void execve_func(char **buffer, struct stat *statbuf __attribute__((unused)), char **envp)
{
	int argc;
	char **argv;
	char *token;
	char **exe;
	char *delim = " ";

	/*count number of arguments*/

	/* Debug print statement before tokenization */
	printf("Original string: %s\n", *buffer);

	argc = 0;
	/*loop for tokenization*/
	token = strtok(*buffer, delim);
	while (token != NULL)
	{
		printf("Token: %s\n", token);
		argc++;
		token = strtok(NULL, delim);
	}

	/* Allocate memory for argv*/
	argv = (char **)malloc((argc + 1) * sizeof(char *));
	if (argv == NULL)
	{
		perror("Error: (malloc)\n");
		free(*buffer);
		exit(EXIT_FAILURE);
	}

	/*argv with arguments/tokens*/

	token = strtok(*buffer, delim);
	for (int i = 0; i < argc; ++i)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
	}
	/*Use null to terminate the argv array*/
	argv[argc] = NULL;

	/* set exe to be first argument */
	exe = argv;

	/*Debug print statements*/
	printf("Execute: %s\n", exe[0]);
	for (int i = 0; exe[i] != NULL; ++i)
		printf("Arg[%d]: %s\n", i, exe[i]);

	execve(exe[0], exe, envp);
	perror("Error: (execve)\n");

	/*Free allocated memory*/
	free(argv);

	exit(EXIT_FAILURE);
}
