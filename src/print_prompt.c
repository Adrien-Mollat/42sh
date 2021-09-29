/*
** EPITECH PROJECT, 2018
** print_prompt.c
** File description:
** print main prompt 42sh
*/

#include "minish.h"

void print_prompt(int status)
{
    char *path = NULL;

    path = getcwd(path, 200);
    if (isatty(0) == 1 && status == 0) {
        my_putstr("\033[1m\033[36m");
        my_putstr(path);
        my_putstr("\033[1m\033[33m");
        my_putstr(" $ > ");
        my_putstr("\033[0m");
    }
    if (isatty(0) == 1 && status == 1) {
        my_putstr("\033[1m\033[31m");
        my_putstr(path);
        my_putstr("\033[1m\033[33m");
        my_putstr(" $ > ");
        my_putstr("\033[0m");
    }
}