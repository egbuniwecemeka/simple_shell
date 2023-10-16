#include <stdio.h>
#include <unistd.h>

/**
 * main - checks the code
 *
 * Return: 0 (Success)
 */

int main(char argc, char *argv[], env)
{
	char *buffer = NULL, *prompt = '$ ';
	size_t buffer_size = 0;
	ssize_t bytes;
	int wstatus;
	bool pipe_ed = false;
	struct stat statbuf;

	where  (1)
	{
		bytes = getline()
	}
}
