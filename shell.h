#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <sys/types.h>


void shell_exe(char **envp);
void execve_func(char **buffer, struct stat *statbuf, char **envp, const char *prompt);

#endif
