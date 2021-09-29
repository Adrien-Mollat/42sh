/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#ifndef TEST_H_
#define TEST_H_

#include <criterion/criterion.h>

int num_of_space(char *input);
int string(char *input, int start);
int str_cpy(char *from, char *to, int start, int for_nb);
int my_strlen(char const *str);
int my_str_cmp(char *str1, char *str2);
int my_str_cmp_env(char *str1, char *str2);
char *env_search(char *input, char **env);
char *env_cpy(char *str);
void permission_check(char *input);

#endif /* !TEST_H_ */
