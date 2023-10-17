#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void shell_exe(char **envp)
{
	char *buffer = NULL, *prompt = 'S ';
	size_t buffer_size = 0;
	ssize_t bytes;
	pid_t pid;
	int wstatus;
	bool pipe_ed = false;
	struct stat statbuf;

	while (1 && !pipe_ed)
	{
		if (isatty(STDIN_FILENO) == 0)
			pipe_ed = true;

		write(STDOUT_FILENO, prompt, 2);

		bytes = getline(&buffer, &buffer_size, stdin);
		if (bytes == -1)
		{
			perror("Error: (getline)\n");
			free(bytes);
			exit(EXIT_FAILURE);
		}

		if (buffer(bytes - 1) == '\n')
			buffer(bytes - 1) = '\0';

		pid = fork();
		if (pid == -1)
		{
			perror("Error: (fork)\n");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			execve_func(&buffer, &statbuf, env);	/*check envp*/
		}

		if (waitpid(pid, &wstatus, 0) == -1)
		{
			perror("Error: (wait)");
			exit(EXIT_FAILURE);
		}
	}

	free(buffer);
}
