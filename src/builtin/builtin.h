#ifndef BUILTLINS_H
#define BUILTLINS_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
extern char *builtin_str[];
int cd(char **args);
int help(char **args);
int xexit(char **args);
int num_of_builtins();
extern int (*builtin_func[])(char **);
#endif