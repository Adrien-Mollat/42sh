/*
** EPITECH PROJECT, 2019
** take_exec_separators
** File description:
** take separators and command of && and ||
*/

#include "minish.h"

void copy_exec_separator(int *coord, char **arg, char ***commands)
{
    for (int j = 0; arg[coord[3]][j] != '\0'; j++) {
        if (my_str_cmp(arg[coord[3]], "||") == 1 ||
            my_str_cmp(arg[coord[3]], "&&") == 1) {
            commands[coord[0]][coord[1]][coord[2]] = '\0';
            commands[coord[0]][coord[1]] = NULL;
            coord[2] = 0;
            coord[1] = -1;
            coord[0] = coord[0] + 1;
            commands[coord[0]] = malloc(sizeof(char *) * (my_tablen(arg) + 1));
            commands[coord[0]][coord[1] + 1] = malloc(sizeof(char) *
                (my_tablen(arg) + 1));
            return;
        }
        else {
            commands[coord[0]][coord[1]][coord[2]] = arg[coord[3]][j];
            coord[2] = coord[2] + 1;
        }
    }
}

char ***take_all_exec_separator(char **arg)
{
    int coord[4] = {0, 0, 0, 0};
    char ***commands = malloc(sizeof(char **) * (my_tablen(arg) + 1));

    commands[0] = malloc(sizeof(char *) * (my_tablen(arg) + 1));

    for (int i = 0; arg[i] != NULL; i++) {
        commands[coord[0]][coord[1]] = malloc(sizeof(char) *
            (my_strlen(arg[i]) + 1));
        coord[3] = i;
        copy_exec_separator(coord, arg, commands);
        if (coord[1] != -1)
            commands[coord[0]][coord[1]][coord[2]] = '\0';
        coord[1] = coord[1] + 1;
        coord[2] = 0;
    }
    commands[coord[0]][coord[1]] = NULL;
    commands[coord[0] + 1] = NULL;
    return commands;
}

int *take_all_separator(char **commands)
{
    int *rep = malloc(sizeof(int) * my_tablen(commands));
    int j = 0;

    for (int i = 0; commands[i] != NULL; i++) {
        if (my_str_cmp(commands[i], "||") == 1) {
            rep[j] = OR_SEP;
            j = j + 1;
        }
        if (my_str_cmp(commands[i], "&&") == 1) {
            rep[j] = AND_SEP;
            j = j + 1;
        }
    }
    return rep;
}