/*
** EPITECH PROJECT, 2018
** concat_str
** File description:
** concat_2_str
*/

#include "minish.h"

char *concat_str(char *str1, char *str2)
{
    char *rep = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 2));
    int i = 0;
    int j = 0;

    while (str1[i] != '\0') {
        rep[j] = str1[i];
        i = i + 1;
        j = j + 1;
    }
    i = 0;
    while (str2[i] != '\0') {
        rep[j] = str2[i];
        i = i + 1;
        j = j + 1;
    }
    rep[j] = '\0';
    return (rep);
}
