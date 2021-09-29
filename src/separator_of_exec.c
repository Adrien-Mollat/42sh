/*
** EPITECH PROJECT, 2019
** separator_of_exec
** File description:
** && and || manager
*/

#include "minish.h"

bool is_other_separator(char **commands)
{
    for (int i = 0; commands[i] != NULL; i++)
        if (my_str_cmp(commands[i], "||") == 1 ||
            my_str_cmp(commands[i], "&&") == 1)
            return true;
    return false;
}

bool which_is_separator(int sep, char **all_exec, char **env,
    instruction_t *instruct)
{
    if (sep == OR_SEP) {
        if (instruct->status == 0)
            return false;
        else
            separator_gestion(all_exec, env, instruct);
    }
    if (sep == AND_SEP) {
        if (instruct->status != 0)
            return false;
        else
            separator_gestion(all_exec, env, instruct);
    }
    return true;
}

void manage_and_sep_and_or_sep(int *sep, char ***all_exec, char **env,
    instruction_t *instruct)
{
    for (int i = 0; all_exec[i] != NULL; i++) {
        if (i == 0)
            separator_gestion(all_exec[i], env, instruct);
        else
            if (!which_is_separator(sep[i-1], all_exec[i], env, instruct))
                return;
    }
}

void separator_of_exec(char **commands, char **env, instruction_t *instruct)
{
    char ***all_exec = NULL;
    int *sep = take_all_separator(commands);

    if (is_other_separator(commands)) {
        all_exec = take_all_exec_separator(commands);
        manage_and_sep_and_or_sep(sep, all_exec, env, instruct);
    }
    else
        separator_gestion(commands, env, instruct);
}