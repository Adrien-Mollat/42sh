/*
** EPITECH PROJECT, 2019
** header
** File description:
** header
*/

#ifndef MINISH_H_
#define MINISH_H_

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <fcntl.h>

#define SETENV_ERROR "setenv: Too many arguments.\n"
#define SETENV_FIRST "setenv: Variable name must begin with a letter.\n"
#define SET_AL "setenv: Variable name must contain alphanumeric characters.\n"
#define UNSETENV_ERROR "unsetenv: Too few arguments.\n"
#define ARCH_ERROR ": Exec format error. Wrong Architecture.\n"

#define HIST_FILE ".history"

typedef struct alias_lines {
    char *init_command;
    char *command;
    struct alias_lines *next;
} alias_lines_t;

typedef struct instruction {
    char ***commands;
    char ***all_commands;
    char **env;
    int *sep;
    int command_nbr;
    int status;
    alias_lines_t *alias_lines;
} instruction_t;

typedef struct separators {
    int *pipes;
    int *separators;
    int nbr_pipe;
    int count;
} separators_t;

enum separator {
    PIPE = 1,
    REDIR = 2,
    DOUBLE_REDIR = 3,
    OR_SEP = 4,
    AND_SEP = 5
};

void signal_interpreter(int sig);
char *my_strcpy(char *);
char *concat_str(char *, char *);
char *add_str(char *, char *);
void loop(char **, char **, instruction_t *, int);
int my_str_cmp(char *, char *);
int my_str_cmp_env(char *, char *);
void my_putchar(char);
int my_putstr(char const *);
int my_strlen(char const *);
char **str_to_arr_core(char *);
int print_env(char **);
void prog_exe(char **, char **, instruction_t *);
int cd_command(char *, char **);
int env_mod(char **, char **);
int env_mod_unset(char **, char **);
char *env_search(char *, char **);
void **tab_realloc(void **);
void error_code(int);
char ***take_all_command(char **, char);
char ***take_all_command_separator(char **);
int nbr_of_commands(char ***);
int my_tablen(char **);
char **my_array_copy(char **);
void print_array(char **);
int is_all_alphanumeric(char *);
void separator_gestion(char **, char **, instruction_t *);
int built_in(char **, char **, alias_lines_t **);
char *separe_separator(char *);
int echo_command(char **);
void print_prompt(int);
bool init_new_line_alias(char *, char *,
                        alias_lines_t **);
void delete_alias(alias_lines_t **);
void print_list_alias(alias_lines_t *);
int alias_command(char *, char *,
                alias_lines_t **);
void check_tab_with_alias_list(char **, alias_lines_t *);
void config_init(void);
int *take_all_separator(char **commands);
char ***take_all_exec_separator(char **arg);
void separator_of_exec(char **commands, char **env, instruction_t *instruct);
int nbr_commands(char **input);
int nbr_of_pipe(int *sep);
void pipe_dup_and_close(separators_t *sep, int *status);
void free_and_exit(instruction_t *instruct);
void manage_pipe_and_redir(separators_t *sep, instruction_t *instruct, int *i,
    char **env);
bool bad_input(char **tab, instruction_t *instruct);

int history_command(char **);

#endif /* !MINISH_H_ */