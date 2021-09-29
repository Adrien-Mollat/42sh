/*
** EPITECH PROJECT, 2018
** alias_command.c
** File description:
** alias command 42sh
*/

#include "minish.h"

void check_tab_with_alias_list(char **tab, alias_lines_t *alias_lines)
{
    int i = 0;
    alias_lines_t *current = alias_lines;

    if (alias_lines == NULL)
        return;
    while (tab[i]) {
        if (my_str_cmp(tab[i], current->init_command) == 1) {
            tab[i] = malloc(sizeof(char) * my_strlen(current->command) + 1);
            tab[i] = current->command;
        }
        i++;
    }
    if (current->next != NULL)
        return (check_tab_with_alias_list(tab, current->next));
}

int alias_command(char *init_command, char *command,
                alias_lines_t **alias_lines)
{
    if (init_command == NULL || command == NULL)
        return (1);
    if (!init_new_line_alias(init_command, command, alias_lines))
        return (84);
    return (1);
}
