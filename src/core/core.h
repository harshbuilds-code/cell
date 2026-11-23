#ifndef CORE_H
#define CORE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../builtin/builtin.h"
#define BOLD_CYAN "\033[1;36m"
#define RESET "\033[0m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_GREEN "\033[1;32m"
int launch(char **args);
int execute(char **args);
char **split_line(char *line);
char *read_line(void);
void shell_loop(void);
#endif
