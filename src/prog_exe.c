/*
** EPITECH PROJECT, 2019
** prog_exe.c
** File description:
** prog exe
*/

#include "minish.h"

char *add_str(char *from, char *to)
{
    int x;
    int length = my_strlen(from) + my_strlen(to);
    char *new_str = malloc(sizeof(char) * (length) + 1);

    if (!new_str || !from)
        return (NULL);
    for (x = 0; x < my_strlen(from); x += 1)
        new_str[x] = from[x];
    for (int y = 0; y < my_strlen(to); y += 1, x += 1)
        new_str[x] = to[y];
    new_str[x] = '\0';
    return (new_str);
}

static char *access_bin(char *input, char **env)
{
    char *path = env_search("PATH", env);
    char *temp_input = input;
    char *mid_path = NULL;

    path = !path ? "/usr/local/bin:/usr/bsd:/bin:/usr/bin" : path;
    if (my_strlen(path) == 1)
        return NULL;
    mid_path = malloc(sizeof(char) * (my_strlen(path) + 2));
    for (int x = 0, y = 0; x <= my_strlen(path); x += 1, y += 1) {
        if (path[x] == ':' || path[x] == '\0') {
            mid_path[y] = '/';
            mid_path[y + 1] = '\0';
            temp_input = add_str(mid_path, input);
            if (access(temp_input, X_OK) == 0)
                return (temp_input);
            y = -1;
        }
        if (y != -1)
            mid_path[y] = path[x];
    }
    return (input);
}

int permission_check(char *input)
{
    struct stat file_st;

    stat(input, &file_st);
    if (access(input, F_OK) != 0) {
        my_putstr(input);
        my_putstr(": Command not found.\n");
        return (0);
    }
    if (S_ISDIR(file_st.st_mode) || access(input, X_OK)) {
        my_putstr(input);
        my_putstr(": Permission denied.\n");
        return (0);
    }
    return (1);
}

void prog_exe(char **av, char **env, instruction_t *instruct)
{
    char *temp_prog = av[0];
    pid_t pid;

    if (built_in(env, av, &instruct->alias_lines) == 0) {
        pid = fork();
        if (pid < 0)
            return;
        if (pid == 0) {
            if (!(temp_prog = access_bin(av[0], env)))
                temp_prog = av[0];
            if (permission_check(temp_prog) != 1)
                exit(1);
            execve(temp_prog, av, env);
            my_putstr(temp_prog);
            my_putstr(ARCH_ERROR);
            exit (1);
        }
        waitpid(pid, &instruct->status, 0);
        error_code(instruct->status);
        free(temp_prog);
    }
}
