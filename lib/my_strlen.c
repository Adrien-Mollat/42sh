/*
** EPITECH PROJECT, 2018
** Strlen
** File description:
** Count char
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return (0);
    while (str[i] != '\0'){
        i += 1;
    }
    return (i);
}
