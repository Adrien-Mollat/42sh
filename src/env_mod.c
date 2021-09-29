/*
** EPITECH PROJECT, 2019
** env mod
** File description:
** modify env
*/

#include "minish.h"

int analyze_first_arg(char *ar)
{
    int ret = 0;

    for (int x = 0; ar[x] != '\0'; x += 1) {
        ret = 0;
        if ((ar[x] >= 'A' && ar[x] <= 'Z') || (ar[x] >= 'a' && ar[x] <= 'z'))
            ret = 2;
        if ((ar[x] >= '0' && ar[x] <= '9') || ar[x] == '_')
            ret = 1;
        if (x == 0 && ret != 2) {
            my_putstr(SETENV_FIRST);
            return (0);
        }
        if (ret == 0)
            break;
    }
    if (ret < 1)
        my_putstr(SET_AL);
    return (ret);
}

void insert_env(char *str, char **env)
{
    int x;

    for (x = 0; env[x] != NULL; x += 1)
        if (my_str_cmp_env((env[x]), str) == 1) {
            env[x] = str;
            return;
        }
    env[x] = str;
    env[x + 1] = NULL;
}

void env_mod_two(char **av, char **env)
{
    int x;
    int y;
    int length = my_strlen(av[1]) + my_strlen(av[2]);
    char *string = malloc(sizeof(char) * (length + 2));

    for (x = 0; x < my_strlen(av[1]); x += 1)
        string[x] = av[1][x];
    string[x] = '=';
    for (y = my_strlen(av[1]) + 1, x = 0; y <= length; y += 1, x += 1)
        string[y] = av[2][x];
    string[y] = '\0';
    insert_env(string, env);
}

void env_mod_one(char **av, char **env)
{
    av[1][my_strlen(av[1]) + 1] = '\0';
    av[1][my_strlen(av[1])] = '=';
    insert_env(av[1], env);
}

int env_mod(char **av, char **env)
{
    int x = 0;

    for (x = 0; av[x] != NULL; x += 1);
    if (x == 1)
        print_env(env);
    if (x > 1 && analyze_first_arg(av[1]) < 1)
        return (1);
    if (x == 2)
        env_mod_one(av, env);
    if (x == 3)
        env_mod_two(av, env);
    if (x > 3)
        my_putstr(SETENV_ERROR);
    return (1);
}
