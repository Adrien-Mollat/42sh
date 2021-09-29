/*
** EPITECH PROJECT, 2019
** lib test
** File description:
** lib test
*/

#include "test.h"

Test(str_to_arr, str_len)
{
    cr_expect(my_strlen("Hello") == 5);
}

Test(str_to_arr, num_of_words)
{
    cr_expect(num_of_space("Hello  World  !!") == 3);
    cr_expect(num_of_space("Hello  World f !!") == 4);
}

Test(str_to_arr, word_count)
{
    cr_expect(string("Hello  World f !!", 0) == 6);
    cr_expect(string("Hello  Worlds f !!", 7) == 7);
}

Test(str_to_arr, str_cpy)
{
    char *from = "Hello how are you?";
    char *to = malloc(sizeof(char) * 6);

    cr_expect(str_cpy(from, to, 0, 5) == 5);
    cr_assert_str_eq(to, "Hello");
    free(to);
    to = malloc(sizeof(char) * 4);
    cr_expect(str_cpy(from, to, 6, 3) == 3);
    cr_assert_str_eq(to, "how");
    free(to);
}

Test(lib, my_str_cmp)
{
    cr_expect(my_str_cmp("Hello", "Hello") == 1);
    cr_expect(my_str_cmp("Hello", "Hello d") == 0);
    cr_expect(my_str_cmp_env("env=", "env") == 1);
    cr_expect(my_str_cmp_env("tata=titi", "tata") == 1);
    cr_expect(my_str_cmp_env("tata=titi", "tato") == 0);
}
