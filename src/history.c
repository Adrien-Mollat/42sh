/*
** EPITECH PROJECT, 2019
** history
** File description:
** history
*/

#include "minish.h"

static int last_hist(char **tab)
{
    write(0, tab[0], my_strlen(tab[0]));
    return (1);
}

int history_command(char **tab)
{
    if (tab[0][0] == '!' && tab[0][1] == '\0')
        return (0);
    else if (tab[0][0] == '!')
        return last_hist(tab);
    if (!(*tab = malloc(sizeof(char *) * 3)))
        return (84);
    tab[0] = my_strcpy("cat");
    tab[1] = my_strcpy(".history");
    tab[2] = NULL;
    return (0);
}