/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "minish.h"

char *var(alias_lines_t **alias_lines, int fd, int status)
{
    char *string = NULL;
    size_t n = 0;

    print_prompt(0);
    if (getline(&string, &n, stdin) == -1) {
        delete_alias(alias_lines);
        my_putstr("exit\n");
        exit (status % 255);
    }
    string[0] != '\n' ? write(fd, string, my_strlen(string)) : 0;
    for (int x = 0;; x += 1) {
        if (string[x] == '\t')
            string[x] = ' ';
        if (string[x] == '\n') {
            string[x] = '\0';
            break;
        }
    }
    if (string[0] == '\0')
        return (var(alias_lines, fd, status));
    return (string);
}

int built_in(char **env, char **tab, alias_lines_t **alias_lines)
{
    if (my_str_cmp(tab[0], "env") == 1)
        return (print_env(env));
    if (my_str_cmp(tab[0], "setenv") == 1)
        return (env_mod(tab, env));
    if (my_str_cmp(tab[0], "unsetenv") == 1)
        return (env_mod_unset(tab, env));
    if (my_str_cmp(tab[0], "cd") == 1)
        return (cd_command(tab[1], env));
    if (my_str_cmp(tab[0], "history") == 1 || tab[0][0] == '!')
        return (history_command(tab));
    if (my_str_cmp(tab[0], "exit") == 1) {
        delete_alias(alias_lines);
        free(tab);
        exit(0);
    }
    if (my_str_cmp(tab[0], "echo") == 1)
        return (echo_command(tab));
    if (my_str_cmp(tab[0], "alias") == 1)
        return (alias_command(tab[1], tab[2], alias_lines));
    return (0);
}

char *verif_error(char *input)
{
    int i = 0;

    while (input[i] == ' ')
        i = i + 1;
    if (input[i] == ';')
        input[i] = ' ';
    i = my_strlen(input) - 1;
    while (input[i] == ' ')
        i = i - 1;
    if (input[i] == ';')
        input[i] = ' ';
    return input;
}

void loop(char **env, char **tab, instruction_t *instruct, int fd)
{
    char *input = NULL;
    instruct->all_commands = NULL;
    instruct->status = 0;
    instruct->alias_lines = NULL;

    while (1) {
        input = verif_error(separe_separator(var(&instruct->alias_lines, fd,
            instruct->status)));
        tab = str_to_arr_core(input);
        check_tab_with_alias_list(tab, instruct->alias_lines);
        if (tab != NULL)
            instruct->all_commands = take_all_command(tab, ';');
        free(input);
        if (!bad_input(tab, instruct))
            for (int j = 0; instruct->all_commands[j] != NULL; j++)
                separator_of_exec(instruct->all_commands[j], env, instruct);
        print_list_alias(instruct->alias_lines);
    }
}

int main(int ac, char **av, char **env)
{
    int fd;
    char **tab = NULL;
    instruction_t instruct;

    signal(SIGINT, signal_interpreter);
    if (ac != 1) {
        my_putstr(av[1]);
        my_putstr(": No such file or directory.\n");
        return (1);
    }
    if (!(fd = open(HIST_FILE, O_CREAT | O_APPEND | O_RDWR, 00777)))
        return (84);
    loop(env, tab, &instruct, fd);
    free(tab);
    close(fd);
    return (0);
}
