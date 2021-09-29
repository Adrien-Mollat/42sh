/*
** EPITECH PROJECT, 2019
** separe_separator
** File description:
** separe the separator of the commands
*/

#include "minish.h"

char *add_space(char *str, int n)
{
    char *rep = malloc(sizeof(char) * my_strlen(str) + 2);
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (i == n) {
            rep[j] = ' ';
            j = j + 1;
        }
        rep[j] = str[i];
        j = j + 1;
        i = i + 1;
    }
    rep[j] = '\0';
    return rep;
}

char *separe_separator(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (((i != 0 && str[i] == '|' && str[i-1] != '|' )
            && str[i-1] != ' '))
            str = add_space(str, i);
        if (((str[i+1] != '\0' && str[i] == '|' && str[i+1] != '|')
            && str[i+1] != ' '))
            str = add_space(str, i+1);
        if (i != 0 && (str[i] == ';'
            || (str[i] == '>' && str[i-1] != '>')
            || (str[i] == '<' && str[i-1] != '<')
            || (str[i] == '&' && str[i-1] != '&')) && str[i-1] != ' ')
            str = add_space(str, i);
        if (str[i+1] != '\0' && (str[i] == ';'
            || (str[i] == '>' && str[i+1] != '>')
            || (str[i] == '<' && str[i+1] != '<')
            || (str[i] == '&' && str[i+1] != '&')) && str[i+1] != ' ')
            str = add_space(str, i+1);
    }
    return str;
}