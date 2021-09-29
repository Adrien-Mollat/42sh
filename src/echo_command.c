/*
** EPITECH PROJECT, 2019
** echo_command
** File description:
** echo built_in
*/

#include "minish.h"

int echo_command(char **tab)
{
    for (int i = 1; tab[i]; i++) {
        my_putstr(tab[i]);
        if (tab[i + 1])
            my_putchar(' ');
    }
    my_putchar('\n');
    return (1);
}