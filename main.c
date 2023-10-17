#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - checks the code
 *
 * Return: 0 (Success)
 */

int main(int argc, char *argv[], char **env)
{
	char *buffer = NULL, *prompt = '$ ';
	size_t buffer_size = 0;
	ssize_t bytes;
	pid_t pid;
	int wstatus;
	bool pipe_ed = false;
	struct stat statbuf;

	while (1 && !pipe_ed)
	{
		if (isatty(STDIN_FILENO) == 0)
		       piped_ed = true;
		/* write prompt '$ ' to terminal*/
		write(STDOUT_FILENO, prompt, 2);
		bytes = getline(&buffer, &buffer_size, stdin);
		if (bytes == -1)
		{
			perror("Error: (getline)");
			free(bytes);	/* Frees memory if getline fails*/
			exit(EXIT_FAILURE);
		}
		/* Replaces a new line with a terminating null*/
		if (buffer(bytes - 1) == '\n')
			buffer(bytes - 1) = '\0';
		/*Create a process using fork*/
		pid = fork();
		if (pid == -1)
		{
			perror("Error: (fork)\n");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		/* Child process*/
		if (pid == 0)
		{
			execve_func(&buffer, &statbuf, envp)
		}
		/* Ppid waits for child process to terminate*/
		if (waitpid(buffer, &wstatus, 0) == -1)
		{
			perror("Error: (wait)\n");
			exit(EXIT_FAILURE);
		}
	}
	free(buffer);
	return (0);
}
