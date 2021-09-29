/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** copy_an_str
*/

#include "minish.h"

char *my_strcpy(char *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * my_strlen(src));

    while (i != my_strlen(src)) {
            dest[i] = src[i];
            i = i + 1;
        }
        dest[i] = '\0';
    return (dest);
}
