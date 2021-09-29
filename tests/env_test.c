/*
** EPITECH PROJECT, 2019
** env test
** File description:
** env test
*/

#include "test.h"

Test(src, env_cpy)
{
    char *string = NULL;

    string = env_cpy("toto=tata");
    cr_assert_str_eq(string, "tata");
    string = env_cpy("HOME=/Users/Valdsj");
    cr_assert_str_eq(string, "/Users/Valdsj");
}