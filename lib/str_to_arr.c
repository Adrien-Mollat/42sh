/*
** EPITECH PROJECT, 2019
** str to att
** File description:
** string to array
*/

#include "minish.h"

int num_of_space(char *input)
{
    int x = 0;
    int count = 1;

    while (x < my_strlen(input)) {
        if (input[x] == ' ' && input[x - 1] != ' ')
            count += 1;
        x += 1;
    }
    return (count);
}

int str_cpy(char *from, char *to, int start, int for_nb)
{
    int x;

    for (x = 0; x < for_nb; x += 1, start += 1)
        to[x] = from[start];
    to[x] = '\0';
    return (x);
}

int string(char *input, int start)
{
    int x;

    for (x = 0;; x += 1, start += 1)
    if (input[start] == ' ' || input[start] == '\0')
        break;
    return (x + 1);
}

void str_to_arr(char *input, char **tab)
{
    int count = 0;
    int start = 0;
    int nb = 0;

    while (start < my_strlen(input)) {
        if (input[start] == ' ')
            start += 1;
        else if (input[start] == '\n' || input[start] == '\0')
            break;
        else {
            nb = string(input, start);
            tab[count] = malloc(sizeof(char) * nb);
            start += str_cpy(input, tab[count], start, nb - 1);
            count += 1;
            nb = 0;
        }
    }
    tab[count] = NULL;
}

char **str_to_arr_core(char *input)
{
    char **tab = malloc(sizeof(char *) * (num_of_space(input) + 1));

    str_to_arr(input, tab);
    return (tab);
}
