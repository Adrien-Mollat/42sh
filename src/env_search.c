/*
** EPITECH PROJECT, 2019
** env search
** File description:
** env search
*/

#include "minish.h"

char *env_cpy(char *str)
{
    char *string = NULL;
    int x = 0;
    int y = 0;

    while (str[x] != '=')
        x += 1;
    x += 1;
    if (!(string = malloc(sizeof(char) * (my_strlen(str) - x + 1))))
        return (NULL);
    for (y = 0; x < my_strlen(str); x += 1, y += 1)
        string[y] = str[x];
    string[y] = '\0';
    return (string);
}

char *env_search(char *input, char **env)
{
    char *string = NULL;

    for (int x = 0; env[x] != NULL; x += 1)
        if (my_str_cmp_env(env[x], input) == 1)
            string = env_cpy(env[x]);
    return (string);
}
