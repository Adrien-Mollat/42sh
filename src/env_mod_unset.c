/*
** EPITECH PROJECT, 2019
** env mode unset
** File description:
** env mode unset
*/

#include "minish.h"

static void env_remove(int nb, char **env)
{
    for (int x = nb;; x += 1) {
        env[x] = env[x + 1];
        if (env[x] == NULL)
            break;
    }
}

int env_mod_unset(char **av, char **env)
{
    int count;

    for (count = 0; av[count] != NULL; count += 1);
    if (count < 2) {
        my_putstr(UNSETENV_ERROR);
        return (1);
    }
    for (int x = 1; av[x] != NULL; x += 1)
        for (int y = 0; env[y] != NULL; y += 1)
            if (my_str_cmp_env(env[y], av[x]) == 1)
                env_remove(y, env);
    return (1);
}