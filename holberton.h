#ifndef HOLBERTON_H_
#define HOLBERTON_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int execute(char **commands, char **env);
char *_strcpy(char *str);
int num_elems(char *buffer);
char **set_elems(char *buffer, const char *delim, int n);
void free_coms(char **commands, int n);

#endif
