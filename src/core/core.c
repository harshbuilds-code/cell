#include "core.h"
int launch(char **args)
{
    pid_t p;
    p = fork();
    if (p < 0)
    {
        perror("cell");
        return 1;
    }
    else if (p == 0)
    {
        signal(SIGINT, SIG_DFL);
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        int status;
        waitpid(p, &status, 0);
        return 1;
    }

    return 1;
}
int execute(char **args)
{
    if (args == NULL || args[0] == NULL)
    {
        return 1;
    }
    for (int i = 0; i < num_of_builtins(); i++)
    {
        if (strcmp(args[0], builtin_str[i]) == 0)
        {
            return (*builtin_func[i])(args);
        }
    }
    launch(args);
    return 1;
}
char **split_line(char *line)
{
    int i = 0;
    char **tokens = malloc(10 * sizeof(char *));
    char *token = strtok(line, " \t\r\n\a");
    while (token)
    {
        tokens[i] = token;
        token = strtok(NULL, " \t\r\n\a");
        i++;
    }
    tokens[i] = NULL;
    return tokens;
}
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}
void shell_loop(void)
{
    char p[100];
    char *line;
    char **tokens;
    int status;
    do
    {
        printf(BOLD_CYAN "cell" RESET ":" BOLD_BLUE "%s" BOLD_GREEN " ❯ " RESET, getcwd(p, 100));
        line = read_line();
        tokens = split_line(line);
        status = execute(tokens);
        free(tokens);
        free(line);
    } while (status);
}