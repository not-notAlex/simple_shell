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

int execute(char **commands, char **paths, char **agav, char **env);
char *_strcpy(char *str);
char *_strcat(char *str1, char *str2, int check);
int num_elems(char *buffer, const char *delim);
char **set_elems(char *buffer, const char *delim, int n);
void free_com(char **loca, char *tion);
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
int _atoi(char *str);
void moveto_oldpwd(char **env);
int execute_loop(char *buffer, char **env, char **paths, char **av);
void print_error(char **argv, char **commands);
void path_execute(char **path, char **commands, char **argv, int i, char **env);

/**
 * struct system_commands - pairs command name with function
 * @coms: system command name
 * @f: a system function
 * Description: correctly pairs coms and funcs
 */
typedef struct system_commands
{
	char *coms;
	void (*f)(char **commands, char **env);
} sys_coms;

#endif
