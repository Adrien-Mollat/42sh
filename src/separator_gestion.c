/*
** EPITECH PROJECT, 2019
** pipe_gestion.c
** File description:
** pipe file
*/

#include "minish.h"

void multi_separator(instruction_t *instruct, char **env, separators_t *sep)
{
    sep->nbr_pipe = nbr_of_commands(instruct->commands) - 1;
    sep->pipes = malloc(sizeof(int) * (sep->nbr_pipe * 2));
    sep->count = 1;

    for (int i = 0; i != sep->nbr_pipe * 2; i += 2)
        pipe(sep->pipes + i);
    for (int i = 0; instruct->commands[i] != NULL; i++)
        manage_pipe_and_redir(sep, instruct, &i, env);
    for (int i = 0; i != sep->nbr_pipe * 2; i++)
        close(sep->pipes[i]);
    wait(&instruct->status);
    for (int i = 0; i != sep->nbr_pipe * 2 - 1; i++)
        wait(&instruct->status);
}

int *separator_tab(char **tab)
{
    int count = 0;
    int *rep = malloc(sizeof(int) * my_tablen(tab));

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_str_cmp(tab[i], "|") == 1)
            rep[count] = PIPE;
        if (my_str_cmp(tab[i], ">") == 1)
            rep[count] = REDIR;
        if (my_str_cmp(tab[i], ">>") == 1)
            rep[count] = DOUBLE_REDIR;
        if (my_str_cmp(tab[i], "|") == 1 || my_str_cmp(tab[i], ">") == 1 ||
            my_str_cmp(tab[i], ">>") == 1)
            count = count + 1;
    }
    rep[count] = 0;
    return rep;
}

bool bad_input(char **tab, instruction_t *instruct) {
    for (int i = 0; tab[i] != NULL; i++) {
        if ((my_str_cmp(tab[i], "|") == 1 && (i == 0
            || my_str_cmp(tab[i-1], "|") == 1 || my_str_cmp(tab[i-1], ";") == 1
            || tab[i+1] == NULL || my_str_cmp(tab[i+1], "|") == 1 
            || my_str_cmp(tab[i+1], ";") == 1)) || tab[0][0] == '|' 
            || (tab[i][0] == '|' && tab[i][1] == '|' && tab[i][2] == '|')
            || (i != 0 && my_str_cmp(tab[i-1], "&&") == 1 && tab[i][0] == '|')
            || (tab[i][my_strlen(tab[i]) - 1] == '|' && tab[i+1] != NULL
            && my_str_cmp(tab[i+1], "&&") == 1)){
            instruct->status = 1;
            my_putstr("Invalid null command.\n");
            return true;
        }
    }
    return false;
}

void separator_gestion(char **input, char **env, instruction_t *instruct)
{
    separators_t sep;

    instruct->command_nbr = nbr_commands(input);
    instruct->commands = NULL;
    if (instruct->command_nbr == 0)
        return (prog_exe(input, env, instruct));
    sep.separators = separator_tab(input);
    instruct->commands = take_all_command_separator(input);
    multi_separator(instruct, env, &sep);
    for (int x = 0; instruct->commands[x]; x += 1)
        free(instruct->commands[x]);
    free(instruct->commands);
}