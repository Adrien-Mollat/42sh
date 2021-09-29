/*
** EPITECH PROJECT, 2019
** array_management
** File description:
** array_functions
*/

#include "minish.h"

int my_tablen(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i = i + 1;
    return i;
}

char **my_array_copy(char **tab)
{
    char **rep = malloc(sizeof(char *) * (my_tablen(tab) + 10));
    int i = 0;

    while (tab[i] != NULL) {
        rep[i] = my_strcpy(tab[i]);
        i = i + 1;
    }
    rep[i] = NULL;
    return rep;
}

void print_array(char **arr)
{
    for (int i = 0 ; arr[i] != NULL ; i++)
        my_putstr(concat_str(arr[i], "\n"));
}

int is_all_alphanumeric(char *str)
{
    if ((str[0] < 'A' || str[0] > 'z' || (str[0] > 'Z' && str[0] < 'a')) &&
        str[0] != '_')
        return 2;
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if ((str[i] < '0' || str[i] > 'z' || (str[i] > '9' && str[i] < 'A') ||
            (str[i] > 'Z' && str[i] < 'a')) && str[i] != '_')
            return 1;
    }
    return 0;
}