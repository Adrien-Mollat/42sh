/*
** EPITECH PROJECT, 2019
** pipe_and_redir_manager
** File description:
** manage all pipe and redirections
*/

#include "minish.h"

void redirect_function(int i, char **env, separators_t *sep,
    instruction_t *instruct)
{
    int fd;

    if (sep->separators[i] == REDIR)
        fd = open(instruct->commands[i+1][0], O_CREAT | O_TRUNC | O_WRONLY,
            S_IRUSR | S_IWUSR);
    else
        fd = open(instruct->commands[i+1][0], O_CREAT | O_APPEND | O_WRONLY,
            S_IRUSR | S_IWUSR);
    dup2(fd, 1);
    dup2(sep->pipes[sep->count - 3], 0);
    for (int j = 0; j != sep->nbr_pipe * 2; j++)
        close(sep->pipes[j]);
    prog_exe(instruct->commands[i], env, instruct);
    close(fd);
}

void manage_pipe_and_redir(separators_t *sep, instruction_t *instruct, int *i,
    char **env)
{
    if (sep->separators[*i] == PIPE || sep->separators[*i] == 0) {
        if (fork() == 0) {
            pipe_dup_and_close(sep, &instruct->status);
            prog_exe(instruct->commands[*i], env, instruct);
            free_and_exit(instruct);
        }
        sep->count = sep->count + 2;
    }
    if (sep->separators[*i] == REDIR || sep->separators[*i] == DOUBLE_REDIR) {
        if (fork() == 0) {
            redirect_function(*i, env, sep, instruct);
            free_and_exit(instruct);
        }
        *i = *i + 1;
        sep->count = sep->count + 2;
    }
}