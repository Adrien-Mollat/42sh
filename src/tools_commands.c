/*
** EPITECH PROJECT, 2019
** tools_commands
** File description:
** tools of commands separator manager
*/

#include "minish.h"

int nbr_commands(char **input)
{
    int count = 0;

    for (int x = 0; input[x]; x += 1)
        if (input[x][0] == '|' || my_str_cmp(input[x], ">") == 1 ||
            my_str_cmp(input[x], ">>"))
            count += 1;
    return (count);
}

int nbr_of_pipe(int *sep)
{
    int count = 0;

    for (int x = 0; sep[x] != 0; x++)
        if (sep[x] == PIPE)
            count = count + 1;
    return count;
}

void pipe_dup_and_close(separators_t *sep, int *status)
{
    if (sep->count > 1)
        dup2(sep->pipes[sep->count - 3], 0);
    if (sep->count < sep->nbr_pipe * 2 && *status != 1)
        dup2(sep->pipes[sep->count], 1);
    for (int j = 0; j != sep->nbr_pipe * 2; j++)
        close(sep->pipes[j]);
}

void free_and_exit(instruction_t *instruct)
{
    for (int i = 0; instruct->commands[i]; i += 1)
        free(instruct->commands[i]);
    free(instruct->commands);
    if (instruct->status == 256)
        exit(1);
    else
        exit(0);
}