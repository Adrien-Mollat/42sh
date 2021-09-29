/*
** EPITECH PROJECT, 2019
** str_cmp
** File description:
** string compare
*/

#include "minish.h"

int my_str_cmp(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (0);
    for (int x = 0; str1[x] != '\0'; x += 1) {
        if (str1[x] != str2[x])
            return (0);
    }
    return (1);
}

int my_str_cmp_env(char *str1, char *str2)
{
    for (int x = 0; str1[x] != '='; x += 1) {
        if (str1[x] != str2[x])
            return (0);
    }
    return (1);
}