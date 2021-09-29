/*
** EPITECH PROJECT, 2019
** print env
** File description:
** print env
*/

#include "minish.h"

int print_env(char **env)
{
    for (int x = 0; env[x] != NULL; x += 1) {
        my_putstr(env[x]);
        my_putchar('\n');
    }
    return (1);
}