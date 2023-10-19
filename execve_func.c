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
	char *delim = " ";
	int i;

	/* Debug print statement before tokenization 
	printf("Original string: %s\n", *buffer);*/

	argc = 0;
	/*loop for tokenization*/
	token = strtok(*buffer, delim);

	/*Allocate mem for argv*/
	argv = (char **)malloc(2 * sizeof(char *));

	if (argv == NULL)
	{
		perror("Error: (malloc)\n");
		free(*buffer);
		exit(EXIT_FAILURE);
	}

	/*counts & checks number of arguments*/
	while (token != NULL)
	{
		/*printf("Token: %s\n", token);*/
		argc++;
		token = strtok(NULL, delim);

		if (argc > 1)
		{
			perror("Only simple arguments without are allowed\n");
			free(*buffer);
			free(argv);
			exit(EXIT_FAILURE);
		}
	}

	/* Allocate memory for argv using arguments/tokens */
	argv = (char **)malloc((argc + 1) * sizeof(char *));
	if (argv == NULL)
	{
		perror("Error: (malloc)\n");
		free(*buffer);
		exit(EXIT_FAILURE);
	}

	/*Tokenization to fill argv agsin*/

	token = strtok(*buffer, delim);
	for (i = 0; i < argc; ++i)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
	}

	/*Use null to terminate the argv array*/
	argv[argc] = NULL;

	/*Debug print statements
	printf("Execute: %s\n", argv[0]);
	for (i = 0; argv[i] != NULL; ++i)
		printf("Arg[%d]: %s\n", i, argv[i]);*/

	if (execve(argv[0], argv, envp) == -1)
	{
		perror("./hsh");
	}

	/*Free allocated memory*/
	free(argv);

	exit(EXIT_FAILURE);
}
