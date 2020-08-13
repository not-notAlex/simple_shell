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

int execute(char **commands, char **paths);
char *_strcpy(char *str);
char *_strcat(char *str1, char *str2);
int num_elems(char *buffer, const char *delim);
char **set_elems(char *buffer, const char *delim, int n);
void free_coms(char **commands);
char **set_paths(char **env);
int no_slash(char *str);
int get_func(char **commands, char **env);
void print_environment(char **commands, char **env);
int _strcmp(char *str1, char *str2);
int _putchar(char c);
void change_dir(char **commands, char **env);
int _strln(char *str);
char *_strtok(char *str, const char *delim);
void sigint_stop(int sig_num);


typedef struct system_commands
{
	char *coms;
	void (*f)(char **commands, char **env);
} sys_coms;

#endif
