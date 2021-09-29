/*
** EPITECH PROJECT, 2019
** signal handle
** File description:
** handle different type of signal
*/

#include <string.h>
#include "minish.h"

void signal_interpreter(int sig)
{
    sig = sig;
    my_putchar('\n');
    print_prompt(1);
}

void error_code(int trash)
{
    int code = 0;

    if (WIFSIGNALED(trash) == 1)
        code = WTERMSIG(trash);
    if (code == 8)
            my_putstr("Floating exception\n");
    if (code == 11)
            my_putstr("Segmentation fault\n");
}