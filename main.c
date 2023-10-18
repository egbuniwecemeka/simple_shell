#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * main - checks the code
 *
 * Return: 0 (Success)
 */

int main(void)
{
	char *envp[] = {NULL};

	shell_exe(envp);
	return (0);
}
