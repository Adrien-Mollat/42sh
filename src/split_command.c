/*
** EPITECH PROJECT, 2019
** split_command
** File description:
** split all command with pipes
*/

#include "minish.h"

int nbr_of_commands(char ***commands)
{
    int i = 0;

    while (commands[i] != NULL)
        i = i + 1;
    return i;
}

void copy_command_separator(int *coord, char **arg, char ***commands)
{
    for (int j = 0; arg[coord[3]][j] != '\0'; j++) {
        if (my_str_cmp(arg[coord[3]], "|") == 1 || my_str_cmp(
            arg[coord[3]], ">") == 1 || my_str_cmp(arg[coord[3]], ">>") == 1) {
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

void copy_command(int *coord, char **arg, char ***commands, char separator)
{
    for (int j = 0; arg[coord[3]][j] != '\0'; j++) {
        if (arg[coord[3]][j] == separator) {
            commands[coord[0]][coord[1]][coord[2]] = '\0';
            commands[coord[0]][coord[1]] = NULL;
            coord[2] = 0;
            coord[1] = -1;
            coord[0] = coord[0] + 1;
            commands[coord[0]] = malloc(sizeof(char *) * (my_tablen(arg) + 1));
            commands[coord[0]][coord[1] + 1] = malloc(sizeof(char) *
                (my_tablen(arg) + 1));
        }
        else {
            commands[coord[0]][coord[1]][coord[2]] = arg[coord[3]][j];
            coord[2] = coord[2] + 1;
        }
    }
}

char ***take_all_command_separator(char **arg)
{
    int coord[4] = {0, 0, 0, 0};
    char ***commands = malloc(sizeof(char **) * (my_tablen(arg) + 1));

    commands[0] = malloc(sizeof(char *) * (my_tablen(arg) + 1));
    commands[0][0] = malloc(sizeof(char) * (my_tablen(arg) + 1));

    for (int i = 0; arg[i] != NULL; i++) {
        coord[3] = i;
        copy_command_separator(coord, arg, commands);
        if (coord[1] != -1)
            commands[coord[0]][coord[1]][coord[2]] = '\0';
        coord[1] = coord[1] + 1;
        coord[2] = 0;
        commands[coord[0]][coord[1]] = malloc(sizeof(char) *
            (my_tablen(arg) + 1));
    }
    commands[coord[0]][coord[1]] = NULL;
    commands[coord[0] + 1] = NULL;
    return commands;
}

char ***take_all_command(char **arg, char separator)
{
    int coord[4] = {0, 0, 0, 0};
    char ***commands = malloc(sizeof(char **) * (my_tablen(arg) + 1));

    commands[0] = malloc(sizeof(char *) * (my_tablen(arg) + 1));
    for (int i = 0; arg[i] != NULL; i++) {
        commands[coord[0]][coord[1]] = malloc(sizeof(char) *
            (my_strlen(arg[i]) + 1));
        coord[3] = i;
        copy_command(coord, arg, commands, separator);
        if (coord[1] != -1)
            commands[coord[0]][coord[1]][coord[2]] = '\0';
        coord[1] = coord[1] + 1;
        coord[2] = 0;
    }
    commands[coord[0]][coord[1]] = NULL;
    commands[coord[0] + 1] = NULL;
    return commands;
}