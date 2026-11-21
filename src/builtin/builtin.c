#include "builtin.h"
char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};
int num_of_builtins()
{
    return sizeof(builtin_str) / sizeof(char *);
}
int cd(char **args)
{
    if (args[1] == NULL)
    {
        char *home = getenv("HOME");
        if (!home || home == NULL)
        {
            fprintf(stderr, "cd: HOME environment variable not set\n");
        }
        if (chdir(home) != 0)
        {
            perror("cd");
        }
        return 1;
    }
    if (args[2] != NULL)
    {
        perror("cd");
    }
    if (chdir(args[1]) != 0)
    {
        perror("cd");
    }
    return 1;
}
int help(char **args)
{
    if (args[1] != NULL)
    {
        fprintf(stderr, "help: Too many Arguments\n");
        return 1;
    }
    printf("\ncell\n");
    printf("A simple Unix Based Shell\n\n");
    return 1;
}
int xexit(char **args)
{
    if (args[1] != NULL)
    {
        fprintf(stderr, "exit: Too many Arguments");
    }
    exit(0);
}
int (*builtin_func[])(char **) = {
    &cd,
    &help,
    &xexit
};
