#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>


int shell_exe(char **envp);
void execve_func(char **buffer, struct stat *statbuf, char **envp);

#endif
