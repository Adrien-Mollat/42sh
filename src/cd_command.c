/*
** EPITECH PROJECT, 2019
** cd_command.c
** File description:
** cd comman
*/

#include "minish.h"

static void tab_create(char **tab, char *pwd, int mode)
{
    tab[0] = "setenv";
    if (mode == 0)
        tab[1] = "OLDPWD";
    else
        tab[1] = "PWD";
    tab[2] = pwd;
    tab[3] = NULL;
}

static void edit_pwd(char *old_pwd, char *cur_pwd, char **env)
{
    char **tab = malloc(sizeof(char *) * 4);

    if (tab == NULL)
        return;
    tab_create(tab, old_pwd, 0);
    env_mod(tab, env);
    tab_create(tab, cur_pwd, 1);
    env_mod(tab, env);
    free(tab);
}

char *relative_check(char *str, char **env)
{
    int x;

    if (my_str_cmp(str, "home")) {
        str = NULL;
        str = add_str(env_search("HOME", env), str);
    }
    if (str[0] == '~') {
        for (x = 0; str[x] != '\0'; x += 1)
            str[x] = str[x + 1];
        str[x - 1] = '\0';
        str = add_str(env_search("HOME", env), str);
    } else if (str[0] == '-')
        str = env_search("OLDPWD", env);
    return (str);
}

int cd_command(char *str, char **env)
{
    char *old_pwd = NULL;
    char *cur_pwd = NULL;

    old_pwd = getcwd(old_pwd, 0);
    if (str == NULL)
        chdir(env_search("HOME", env));
    else if (str != NULL) {
        if (!(str = relative_check(str, env)))
            my_putstr("No $home variable set.\n");
        else if (chdir(str) < 0) {
            my_putstr(str);
            my_putstr(": Not a directory.\n");
        }
    }
    cur_pwd = getcwd(cur_pwd, 0);
    if (old_pwd == NULL || cur_pwd == NULL)
        return (1);
    edit_pwd(old_pwd, cur_pwd, env);
    return (1);
}