/*
** EPITECH PROJECT, 2018
** INIT NEW ALIAS 42SH
** File description:
** init_new_alias.c
*/

#include "minish.h"

void delete_alias(alias_lines_t **alias_lines)
{
    alias_lines_t *current = *alias_lines;
    alias_lines_t *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *alias_lines = NULL;
}

void print_list_alias(alias_lines_t *alias_lines)
{
    alias_lines_t *current = alias_lines;

    while (current != NULL) {
        my_putstr(current->init_command);
        my_putchar('\n');
        my_putstr(current->command);
        current = current->next;
    }
}

bool init_new_line_alias(char *init_command, char *command,
                        alias_lines_t **alias_line)
{
    alias_lines_t *new_node = malloc(sizeof(alias_lines_t));
    alias_lines_t *current = *alias_line;

    if (new_node == NULL)
        return (false);
    new_node->init_command = init_command;
    new_node->command = command;
    new_node->next = NULL;
    if (*alias_line == NULL) {
        *alias_line = new_node;
        return (true);
    }
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
    return (true);
}
